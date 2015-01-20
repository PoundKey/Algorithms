# CPSC 314 Computer Graphics

### OpenGL Pipeline
![Vertex Shader](./img/vshader.png)
#### Vertex Shader
- Shapes are “discretized” into primitives: __triangles__, line segments, ...
- Display objects are composed of arrays of flat surfaces (typically triangles) and vertices define the location and other attributes of the corners of the surfaces.
- Vertices are stored in a vertex buffer.
- When a draw call is issued, each of the vertices passes through the vertex shader
- On input to the vertex shader, each vertex (black) has associated attributes.
- On output, each vertex (cyan) has a value for gl_Position and for its varying variables.

#### Rasterization (光栅化)
- The data in gl_Position are used to place the three vertices of the triangle on a virtual screen.
- The rasterizer figures out which pixels (orange) are inside the triangle and interpolates the varying variables from the vertices to each of these pixels.

![gl_Position](./img/glpos.png)

#### Fragment Shader
- Each pixel (orange) is passed through the fragment shader, which computes the final color of the pixel (pink).
- The pixel is then placed in the framebuffer for display.
- By changing the fragment shader, we can simulate light reflecting off of different kinds of materials.

![Fragment Shader](./img/frag.png)

### Texture Mapping
![Texture Mapping](./img/texture.png)

- A simple geometric object described by a small number of triangles.
- Details stored in an auxiliary image called a texture.
- Traingles <=> Textures map to form graphics

---
### Linear Algebra

#### Points and Vectors
- A vertex is not a point, it consists of attributes such as: point, normal, color, neighbours...
- Vector = Magnitude + Direction
- Magnitude of a vector = Length = Norm of a vector = ||a|| = Sqrt(a<sub>1</sub>^2 + a<sub>2</sub>^2 + a<sub>3</sub>^2 + ... + a<sub>n</sub>^2)
- Vector space: eg. R<sup>2</sup> = 2D space, R<sup>3</sup> = 3D space (An infinitely large set of vectors, where each of those vectors have n components.)
- A vector space is a set V on which two operations + and · are defined, called vector addition and scalar multiplication.
	- Closure: If u and v are any vectors in V, then the sum   u + v   belongs to V.
	- Closure: If v in any vector in V, and c is any real number, then the product   c · v   belongs to V.

__Geometric data types__: points are shown as dots, and vectors as arrows.  

![Notation](./img/noc.png)

#### Linear combinations and span
Let V be a R-vector space and v<sub>1</sub>,...,v<sub>k</sub> ∈ V. A linear combination of these vectors is any expression of the form:  
_c<sub>1</sub>v<sub>1</sub> + c<sub>2</sub>v<sub>2</sub> + ... + c<sub>k</sub>v<sub>k</sub>_  
where the coefficients c<sub>1</sub>, c<sub>2</sub> ... c<sub>k</sub> are scalars.

- span(v<sub>1</sub>,...,v<sub>k</sub>) = R<sup>k</sup>

#### Linear independence
Let A = { v<sub>1</sub>, v<sub>2</sub>, …, v<sub>r</sub> } be a collection of vectors from R<sup>n</sup> . If r > 2 and at least one of the vectors in A _can be written as a linear combination of the others_, then A is said to be __linearly dependent__. The motivation for this description is simple: At least one of the vectors depends (linearly) on the others. On the other hand, if no vector in A is said to be a _linearly independent set._

#### Subspace of R<sup>n</sup>
Let V be a subset of R<sup>n</sup>, V is a subspace of R<sup>n</sup> iff:  

- Contains the 0 vector
- Closure under addition: the sum of any two elements in V is an element of V.
- Closure under scalar multiplication: every scalar multiple of an element in V is an element of V
- eg. The set V = {(x, 3x): x ∈ R} is a Euclidean vector space, a subspace of R<sup>2</sup>.

#### Basis
Let V be a subspace of R<sup>n</sup> for some n. A collection B = { v<sub>1</sub>, v<sub>2</sub>, …, v<sub>r</sub>  } of vectors from V is said to be a basis for V if B is linearly independent and spans V. (Minimal set of vectors that span V, we can use a basis as a way to produce any of the vectors in the space.)

#### Dot product
Vector a: ( a<sub>1</sub>, a<sub>2</sub>, …, a<sub>n</sub> ), Vector b: ( b<sub>1</sub>, b<sub>2</sub>, …, b<sub>n</sub> )  
_a · b = a<sub>1</sub> × b<sub>1</sub> + a<sub>2</sub> × b<sub>2</sub> + ... + a<sub>n</sub> × b<sub>n</sub>_  
a · a = ||a||<sup>2</sup> 

![dot product](./img/eg.png)

#### Cross product
 The cross product a × b of two linearly independent vectors a and b is a vector that is perpendicular to both. (Orthogonal)

![cross product](http://www.mathsisfun.com/algebra/images/cross-product.gif)
![cross product](http://dj1hlxw0wr920.cloudfront.net/userfiles/wyzfiles/5141da12-b501-46d4-9f65-d9bd69c3afd2.gif)


#### Orthogonal
Two vectors are orthogonal if a · b = 0, which implies that Θ = 90. (Perpendicular)

#### Unit Vector
A vector with has a length of 1. (||v|| = 1)

#### Orthonormal basis
> A basis in which all vectors are orthogonal, and have norm = 1.

- all vectors are unit vectors
- all vectors are orthogonal
- linearly independent
- eg. { (1, 0, 0), (0, 1, 0), (0, 0, 1) }

Dot product of two vectors u, v in an orthonormal basis:  
_u · v = 0_

#### Transformation
Def: function operating on vectors. (e.g., T: R<sup>3</sup> -> R<sup>2</sup> == f: x -> y )

#### Linear Transformation
A linear transformation between two vector spaces V and W is a map T: V -> W such that the following hold:

-  T(v<sub>1</sub>+v<sub>2</sub>) = T(v<sub>1</sub>)+T(v<sub>2</sub>) for any vectors v<sub>1</sub> and v<sub>2</sub> in V. (additivity)
- T(av) = aT(v) for any scalar a. (homogeneity of degree 1)

#### Matrix
![cross product](http://upload.wikimedia.org/wikipedia/commons/thumb/b/bb/Matrix.svg/247px-Matrix.svg.png)

#### Matrix-vector product
 If A is an m x n matrix (i.e., with n columns), then the product Ax is defined for n x 1 column vectors x, resulting in m x 1 column vectors.  
The general formula for a matrix-vector product is:

![Matrix-vector product](./img/mvpro.png)

__Note__: Can be also viewed as linear combination or span( v<sub>1</sub>, v<sub>2</sub>, …, v<sub>n</sub> = span(A) )

#### Identity and Inverse 

---
Let V be a R-vector space and v<sub>1</sub>,...,v<sub>k</sub> ∈ V. If v<sub>k</sub> is in the span of v<sub>1</sub>, ..., v<sub>k-1</sub>, then:  
 _span{v<sub>1</sub>,...,v<sub>k</sub>} = span{v<sub>1</sub>,...,v<sub>k-1</sub>}_


>Theorem 1: Given a system of n equations and m unknowns there will be one of three
possibilities for solutions to the system.

>1. There will be no solution.
2. There will be exactly one solution.
3. There will be infinitely many solutions.

>If there is no solution to the system we call the system inconsistent and if there is at least one solution to the system we call it consistent.


