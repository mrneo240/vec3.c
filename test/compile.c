#include "../add.h"
#include "../angle.h"
#include "../clone.h"
#include "../copy.h"
#include "../create.h"
#include "../cross.h"
#include "../distance.h"
#include "../divide.h"
#include "../dot.h"
#include "../equal.h"
#include "../fromValues.h"
#include "../inverse.h"
#include "../length.h"
#include "../lerp.h"
#include "../max.h"
#include "../min.h"
#include "../multiply.h"
#include "../negate.h"
#include "../normalize.h"
#include "../random.h"
#include "../rotateX.h"
#include "../rotateY.h"
#include "../rotateZ.h"
#include "../scale.h"
#include "../scaleAndAdd.h"
#include "../set.h"
#include "../squaredDistance.h"
#include "../squaredLength.h"
#include "../subtract.h"
#include "../transformMat3.h"
#include "../transformMat4.h"
#include "../transformQuat.h"
#include "../type.h"

#include "../float_cmp.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

vec3 _(float x, float y, float z) {
  return vec3_set(vec3_create(), x, y, z);
}

int eq(float a, float b) {
  return float_cmp(a, b, 1);
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
  float zero[3] = {0, 0, 0};
  vec3 first = vec3_create();
  assert(first[0] == 0);
  assert(first[1] == 0);
  assert(first[2] == 0);

  // ensure zero fill
  assert(vec3_equal(first, zero));

  vec3_set(first, 1, 2, 3);
  assert(vec3_equal(first, _(1, 2, 3)));

  first = vec3_set(first, 4, 5, 6);
  assert(vec3_equal(first, _(4, 5, 6)));

  assert(
    vec3_equal(
      vec3_add(vec3_create(), _(1, 1, 1), _(2, 2, 2)),
      _(3, 3, 3)
    )
  );

  vec3 clone = vec3_clone(first);
  assert(vec3_equal(first, clone));
  assert(first != clone);

  vec3 copy = vec3_copy(vec3_create(), first);
  assert(vec3_equal(first, copy));

  assert(
    vec3_equal(
      _(0, 0, 1),
      vec3_cross(
        vec3_create(),
        _(1, 0, 0),
        _(0, 1, 0)
      )
    )
  );

  assert(100 == vec3_distance(_(0, 0, 0), _(100, 0, 0)));

  assert(
    vec3_equal(
      _(2, 3, 4),
      vec3_divide(
        vec3_create(),
        _(4, 6, 8),
        _(2, 2, 2)
      )
    )
  );

  assert(vec3_equal(_(1, 2, 3), vec3_fromValues(1, 2, 3)));

  assert(
    vec3_equal(
      _(.5, .25, .125),
      vec3_inverse(
        vec3_create(),
        _(2, 4, 8)
      )
    )
  );

  assert(
    vec3_equal(
      _(8, 12, 16),
      vec3_multiply(
        vec3_create(),
        _(4, 6, 8),
        _(2, 2, 2)
      )
    )
  );

  assert(
    vec3_equal(
      _(-2, -4, -8),
      vec3_negate(
        vec3_create(),
        _(2, 4, 8)
      )
    )
  );

  assert(100 == vec3_squaredDistance(
    _(0, 0, 0),
    _(10, 0, 0)
  ));

  assert(
    vec3_equal(
      _(1, 2, 3),
      vec3_subtract(
        vec3_create(),
        _(5, 6, 7),
        _(4, 4, 4)
      )
    )
  );

  assert(
    vec3_equal(
      vec3_random(vec3_create(), 1.0),
      _(0.675975f,0.000033f,-0.736924f)
    )
  );

  assert(eq(1.570796, vec3_angle(_(0, 1, 0), _(1, 0, 0))));

  assert(
    vec3_equal(
      _(1, 4, 8),
      vec3_max(
        vec3_create(),
        _(-1, 4, -8),
        _(1, -4, 8)
      )
    )
  );

  assert(
    vec3_equal(
      _(-1, -4, -8),
      vec3_min(
        vec3_create(),
        _(-1, 4, -8),
        _(1, -4, 8)
      )
    )
  );

  assert(
    vec3_equal(
      _(2, 2, 2),
      vec3_lerp(
        vec3_create(),
        zero,
        _(4, 4, 4),
        .5f
      )
    )
  );

  assert(
    vec3_equal(
      _(4, 4, 4),
      vec3_scale(
        vec3_create(),
        _(1, 1, 1),
        4.0f
      )
    )
  );

  assert(
    vec3_equal(
      _(0, -10, -5),
      vec3_rotateX(
        vec3_create(),
        _(0, 10, 5),
        zero,
        3.1459f
      )
    )
  );

  float m3[9] = {
    1, 0, 0,
    5, 5, 1,
    5, 0, 1
  };

  vec3 m3v3 = vec3_transformMat3(
    vec3_create(),
    _(1, 1, 1),
    m3
  );

  assert(vec3_equal(_(22, 15, 4), m3v3));

  float m4[16] = {
    1, 0, 0, 0,
    0, 0.9689124226570129, 0.24740396440029144, 0,
    0, -0.24740396440029144, 0.9689124226570129, 0,
    0, 9.68912410736084, 2.4740395545959473, 1
  };

  vec3 m4v3 = vec3_transformMat4(
    vec3_create(),
    _(0, 0, 0),
    m4
  );

  float q[4] = {
    0.38268f, 0, 0, 0.92388f
  };

  vec3 qv3 = vec3_create();
  vec3_transformQuat(qv3, qv3, q);
  assert(vec3_equal(qv3, _(0, -7.071067f, 7.071067f)));
  return 1;
}
