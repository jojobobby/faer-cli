#version 400

precision lowp float;

layout (location = 0) in vec4 vertUV;

out vec2 uv;

uniform vec4 vertScale;
uniform vec2 vertPos;

void main() {
    gl_Position = vec4(-(vertUV.x * vertScale.x + vertUV.y * vertScale.y) + vertPos.x,
        ((vertUV.x * vertScale.z + vertUV.y * vertScale.w) + vertPos.y), 0, 1);
    uv = vertUV.zw;
}