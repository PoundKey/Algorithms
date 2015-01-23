# GLSL: OpenGL Shading Language

### Introduction
- C-like, with data types: 
	- vec3, vec4, dvec4, mat4, sampler2D ...
	- \<matrix-vector multiplication\>, reflect, refract
- Used for both vertex shaders and fragment shaders, with small differences

### Summary of Key GLSL Concepts
- ‘uniform’ type qualifier
	- Same for all vertices
- “in”, “out”, “varying” type qualifiers configure data flow in the pipeline.
- “in” type qualifiers
	- Input from previous shader stage
	- For vertex shaders, these are per-vertex attributes
- “out” type qualifiers
	- Outputs to next stage
	- gl_position is built-in output variable that must be set before rasterization
- “varying” type qualifiers
	- Equivalent to “out” for VS, “in” for FS
	- Deprecated since GLSL 1.3, Three.js only supports it at present
- Support for geometry, vector and matrix arithmetic
	- length, distance, dot, cross, normalize, reflect
- Compiled by the WebGL, at runtime

__Sample code__:
```glsl

#version 130
uniform float uVertexScale;

in vec2 aPosition;
in vec3 aColor;
in vec2 aTexCoord0, aTexCoord1;

out vec3 vColor;
out vec2 vTexCoord0, vTexCoord1;

void main() {
	gl_Position = vec4(aPosition.x * uVertexScale, aPosition.y, 0,1);
	vColor = aColor;
	vTexCoord0 = aTexCoord0;
	vTexCoord1 = aTexCoord1;
} 
```

### Three.js
- THREE.ShaderMaterial() lets you set shaders, uniforms
- Built-in uniforms and attributes
- Vertex attributes (position, normal, and uv) + uniforms (modelView matrix and cameraPosition)
