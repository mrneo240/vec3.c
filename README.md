# gl-vec3

[![stable](http://badges.github.io/stability-badges/dist/stable.svg)](http://github.com/badges/stability-badges)

Part of a fork of [@toji](http://github.com/toji)'s
[gl-matrix](http://github.com/toji/gl-matrix) to c and split into smaller pieces: this
package contains `glMatrix.vec3`.

## Install

`npm install vec3.c`

## Usage

__main.c__
```c
#include <vec3/type.h>
#include <vec3/create.h>
#include <vec3/set.h>
#include <stdio.h>

int main() {
  vec3 a = vec3_create();
  vec3_set(a, 1.4, 2, -5);
  printf("hello world! (%f, %f, %f)\n", a[0], a[1], a[2]);
}
```

compiled with `gcc main.c -o main -Inode_modules/vec3.c/include`

### with cmake

__CMakeLists.txt
```
cmake_minimum_required(VERSION 3.2)
project (vec3-test)
file(GLOB CMAKE_INCLUDES "node_modules/*/CMakeLists.txt")
include(${CMAKE_INCLUDES})
add_executable(main main.c)
```

## API

  - [vec3_add()](#addoutvec3avec3bvec3)
  - [vec3_angle()](#angleavec3bvec3)
  - [vec3_clone()](#cloneavec3)
  - [vec3_copy()](#copyoutvec3avec3)
  - [vec3_create()](#create)
  - [vec3_cross()](#crossoutvec3avec3bvec3)
  - [vec3_distance()](#distanceavec3bvec3)
  - [vec3_divide()](#divideoutvec3avec3bvec3)
  - [vec3_dot()](#dotavec3bvec3)
  - [vec3_equal()](#equalavec3bvec3)
  - [vec3_fromValues()](#fromvaluesxnumberynumberznumber)
  - [vec3_inverse()](#inverseoutvec3avec3)
  - [vec3_length()](#lengthavec3)
  - [vec3_lerp()](#lerpoutvec3avec3bvec3tnumber)
  - [vec3_max()](#maxoutvec3avec3bvec3)
  - [vec3_min()](#minoutvec3avec3bvec3)
  - [vec3_multiply()](#multiplyoutvec3avec3bvec3)
  - [vec3_negate()](#negateoutvec3avec3)
  - [vec3_normalize()](#normalizeoutvec3avec3)
  - [vec3_random()](#randomoutvec3scalenumber)
  - [vec3_rotateX()](#rotatexoutvec3avec3bvec3cnumber)
  - [vec3_rotateY()](#rotateyoutvec3avec3bvec3cnumber)
  - [vec3_rotateZ()](#rotatezoutvec3avec3bvec3cnumber)
  - [vec3_scale()](#scaleoutvec3avec3bnumber)
  - [vec3_scaleAndAdd()](#scaleandaddoutvec3avec3bvec3scalenumber)
  - [vec3_set()](#setoutvec3xnumberynumberznumber)
  - [vec3_squaredDistance()](#squareddistanceavec3bvec3)
  - [vec3_squaredLength()](#squaredlengthavec3)
  - [vec3_subtract()](#subtractoutvec3avec3bvec3)
  - [vec3_transformMat3()](#transformmat3outvec3avec3mmat4)
  - [vec3_transformMat4()](#transformmat4outvec3avec3mmat4)
  - [vec3_transformQuat()](#transformquatoutvec3avec3qquat)

## vec3_add(out:vec3, a:vec3, b:vec3)

  Adds two vec3's

## vec3_angle(a:vec3, b:vec3)

  Get the angle between two 3D vectors

## vec3_clone(a:vec3)

  Creates a new vec3 initialized with values from an existing vector

## vec3_copy(out:vec3, a:vec3)

  Copy the values from one vec3 to another

## vec3_create()

  Creates a new, empty vec3

## vec3_cross(out:vec3, a:vec3, b:vec3)

  Computes the cross product of two vec3's

## vec3_distance(a:vec3, b:vec3)

  Calculates the euclidian distance between two vec3's

## vec3_divide(out:vec3, a:vec3, b:vec3)

  Divides two vec3's

## vec3_dot(a:vec3, b:vec3)

  Calculates the dot product of two vec3's

## vec3_equal(a:vec3, b:vec3)

  returns whether the two vectors are near equal

## vec3_fromValues(x:Number, y:Number, z:Number)

  Creates a new vec3 initialized with the given values

## vec3_inverse(out:vec3, a:vec3)

  Returns the inverse of the components of a vec3

## vec3_length(a:vec3)

  Calculates the length of a vec3

## vec3_lerp(out:vec3, a:vec3, b:vec3, t:Number)

  Performs a linear interpolation between two vec3's

## vec3_max(out:vec3, a:vec3, b:vec3)

  Returns the maximum of two vec3's

## vec3_min(out:vec3, a:vec3, b:vec3)

  Returns the minimum of two vec3's

## vec3_multiply(out:vec3, a:vec3, b:vec3)

  Multiplies two vec3's

## vec3_negate(out:vec3, a:vec3)

  Negates the components of a vec3

## vec3_normalize(out:vec3, a:vec3)

  Normalize a vec3

## vec3_random(out:vec3, [scale]:Number)

  Generates a random vector with the given scale

## vec3_rotateX(out:vec3, a:vec3, b:vec3, c:Number)

  Rotate a 3D vector around the x-axis

## vec3_rotateY(out:vec3, a:vec3, b:vec3, c:Number)

  Rotate a 3D vector around the y-axis

## vec3_rotateZ(out:vec3, a:vec3, b:vec3, c:Number)

  Rotate a 3D vector around the z-axis

## vec3_scale(out:vec3, a:vec3, b:Number)

  Scales a vec3 by a scalar number

## vec3_scaleAndAdd(out:vec3, a:vec3, b:vec3, scale:Number)

  Adds two vec3's after scaling the second operand by a scalar value

## vec3_set(out:vec3, x:Number, y:Number, z:Number)

  Set the components of a vec3 to the given values

## vec3_squaredDistance(a:vec3, b:vec3)

  Calculates the squared euclidian distance between two vec3's

## vec3_squaredLength(a:vec3)

  Calculates the squared length of a vec3

## vec3_subtract(out:vec3, a:vec3, b:vec3)

  Subtracts vector b from vector a

## vec3_transformMat3(out:vec3, a:vec3, m:mat4)

  Transforms the vec3 with a mat3.

## vec3_transformMat4(out:vec3, a:vec3, m:mat4)

  Transforms the vec3 with a mat4.
  4th vector component is implicitly '1'

## vec3_transformQuat(out:vec3, a:vec3, q:quat)

  Transforms the vec3 with a quat

## License

[zlib](http://en.wikipedia.org/wiki/Zlib_License). See [LICENSE.md](https://github.com/stackgl/gl-vec3/blob/master/LICENSE.md) for details.
