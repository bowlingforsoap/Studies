There is one weird thing that makes GLSL different from most other programming languages -- all GLSL programs must use a finite amount of memory and terminate in a finite time. This means 'no infinite loops', 'no recursion', 'no memory allocation' and 'no strings'.

In GLSL, there only 'three scalar types':
  bool - which stores a logical truth value of either true or false
  int - which stores a signed integer value
  float - which is a fractional number

Floating point variables are declared with an optional 'precision specifier' that tells the GPU how many bits to use when representing a variable. The types are:
  lowp - Lowest precision supported on the available hardware: lowp float t = 1.0;
  mediump - Default precision supported on the hardware: mediump float middle;
  highp - Highest precision supported on the hardware: highp float zzz = -1.5;

Writing precision specifiers all the time can be a little tedious, so to save some keystrokes you can 'declare the precision of all floating point numbers' in your code using the precision statement:
  //Now all floats are high precision
  precision highp float;
  //Equivalent to: highp float x = -0.1;
  float x = -0.1;
  //Declares a 3D high precision floating point
  //vector with components (1,2,3)
  vec3 v(1.0, 2.0, 3.0);
  //Create a low precision 2D vector with all
  //components set to 2
  lowp vec2 p = vec2(2.0);
  //Unpack first 3 components from v into q and
  //set last component to 1.0
  highp vec4 q = vec4(v, 1.0);
  //A 2D boolean vector with true and false
  //components
  bvec2 foo(true, false);

GLSL comes with built in 'types for small vectors' with up to 4 components:
  bvec2, bvec3, bvec4: Boolean vector
  ivec2, ivec3, ivec4: Integer vector
  vec2, vec3, vec4: Floating point vector

'In/out'
While functions in GLSL return a single value, it is possible to simulate multiple returns using 'reference types'. This is done using the following 'type qualifiers for procedure arguments':
  in Passes the argument by /value (default behaviour; The parameter will be passed by value to the function and the values stays the say after the procedure finishes, even though inside it may change)
  inout Passes the argument by reference /(The value can be modified by the function and the changes are preserved after the function exits)
  out The argument is uninitialized, but writing to the value updates the parameter /(value can not be read)
  const The argument is a constant value

  For 'example':
  precision mediump float;

  void testFunction(
    in float x,
    inout float y,
    out float z,
    const float w
  ) {
    x += 1.0;
    y += x;
    z = x + y + w;
  }

  void test() {
    float x=1.0, y=1.0, z=0.0, w=-1.0;
    testFunction(x, y, z, w);
    //Now:
    //  x == 1.0
    //  y == 3.0
    //  z == 4.0
    //  w == -1.0
  }

'Built-ins' (functions, aka subroutines, aka procedures)
Finally, GLSL comes with a 'collection of builtin functions' for performing 'common mathematical operations'. Here is /an (incomplete) list of built in functions for operating on scalar datatypes, based on types:
  Unit conversion: radians, degrees
  Trigonometry: sin, cos, tan, asin, acos, atan
  Calculus: exp, log, exp2, log2
  Algebra: pow, sqrt, inversesqrt
  Rounding: floor, ceil, fract, mod, step
  Magnitude: abs, sign, min, max, clamp
  Interpolation: mix
In addition to the standard arithmetic functions, vectors also support several 'special geometric operations':
  #length(p) returns the euclidean length of p
  #distance(a,b) returns the euclidean distance between a and b
  #dot(a,b) computes vector dot product of a and b
  #cross(a,b) computes the cross product of two 3 vectors
  #normalize(a) rescales a to unit length
  #faceforward(n, I, nr) reorient a normal to point away from a surface
  #reflect(I, N) - reflects a vector I along the axis N
  #refract(I, N, eta) - applies a refractive transformation to I according to Snell''s law
GLSL also supports 'component-wise comparison operations for vectors'. These are implemented as routines that take a pair of vectors and return a bvec whose entries correspond to the value of the predicate:
  #lessThan(a,b)
  #lessThanEqual(a,b)
  #greaterThan(a,b)
  #greaterThanEqual(a,b)
  #equal(a,b)
'Boolean vectors' also support the following 'special aggregate operations':
  #any(b) returns true if any component of b is true, false otherwise
  #all(b) returns true if all components of b are true, false otherwise
  #not(b) negates the logical value of the components of b

'Syntatic sugar'
GLSL has a lot of syntactic sugar for 'manipulating and accessing the components of vectors'. There are 3 basic types of notation, xyzw, rgba, and stuv. These are interpreted and related as follows:
  First component of p  = p.x = p.r = p.s = p[0]
  Second component of p = p.y = p.g = p.t = p[1]
  Third component of p  = p.z = p.b = p.u = p[2]
  Fourth component of p = p.w = p.a = p.v = p[3]
'Ranges and subtypes of vectors' can also be selected using the same symbols. For example,
  vec4 p = vec4(1, 2, 3, 4);
  vec2 q = p.xy;   //q = vec2(1, 2)
  vec2 r = p.bgr;  //r = vec3(3, 2, 1)
  vec3 a = p.xxy;  //a = vec3(1, 1, 2)

!!!'Branches in GLSL are very expensive' so they should be used sparingly!!!
