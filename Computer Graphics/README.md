# CPSC 304 Computer Graphics

### OpenGL Pipeline
![Vertex Shader](./img/vshader.png)
#### Vertex Shader
- Shapes are “discretized” into primitives: __triangles__, line segments, ...
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
- eg. The set V = {(x, 3 x): x ∈ R} is a Euclidean vector space, a subspace of R<sup>2</sup>.

#### Basis
Let V be a subspace of R<sup>n</sup> for some n. A collection B = { v<sub>1</sub>, v<sub>2</sub>, …, v<sub>r</sub>  } of vectors from V is said to be a basis for V if B is linearly independent and spans V. (Minimal set of vectors that span V, without redundancy.)

#### Dot product
Vector a: ( a<sub>1</sub>, a<sub>2</sub>, …, a<sub>n</sub> ), Vector b: ( b<sub>1</sub>, b<sub>2</sub>, …, b<sub>n</sub> )  
_a · b = a<sub>1</sub> × b<sub>1</sub> + a<sub>2</sub> × b<sub>2</sub> + ... + a<sub>n</sub> × b<sub>n</sub>_  
a · b = ||a||<sup>2</sup> 

![dot product](./img/eg.png)

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
_u · v = u<sub>1</sub> × v<sub>1</sub> + u<sub>2</sub> × v<sub>2</sub> + ... + u<sub>n</sub> × v<sub>n</sub>_

---
Let V be a R-vector space and v<sub>1</sub>,...,v<sub>k</sub> ∈ V. If v<sub>k</sub> is in the span of v<sub>1</sub>, ..., v<sub>k-1</sub>, then:  
 _span{v<sub>1</sub>,...,v<sub>k</sub>} = span{v<sub>1</sub>,...,v<sub>k-1</sub>}_


>Theorem 1: Given a system of n equations and m unknowns there will be one of three
possibilities for solutions to the system.

>1. There will be no solution.
2. There will be exactly one solution.
3. There will be infinitely many solutions.

>If there is no solution to the system we call the system inconsistent and if there is at least one solution to the system we call it consistent.


