#version 330 core

layout (location = 0) in vec2 attrib_vertex;
layout (location = 1) in vec2 attrib_tex_coords;

out vec2 varying_attrib_tex_coords;

uniform vec2 u_vec_pos;
uniform mat4 u_mat_view;
uniform float u_float_z_detph;

void main() {
    gl_Position = u_mat_view * vec4(attrib_vertex + u_vec_pos, u_float_z_detph * 0.001f, 1.0f);
    varying_attrib_tex_coords = attrib_tex_coords;
}