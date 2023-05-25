#version 400

precision lowp float;

layout (location = 0) in vec4 vertUV;
layout (location = 1) in vec2 lbUV;
layout (location = 2) in vec2 tbUV;
layout (location = 3) in vec2 rbUV;
layout (location = 4) in vec2 bbUV;
layout (location = 5) in vec2 bUV;

out vec2 baseUV;
out vec2 uv;
out vec2 leftBlendUV;
out vec2 topBlendUV;
out vec2 rightBlendUV;
out vec2 bottomBlendUV;

void main() {
    gl_Position = vec4(vertUV.xy, 0, 1);
    baseUV = vertUV.zw;
    uv = bUV;
    leftBlendUV = lbUV;
    topBlendUV = tbUV;
    rightBlendUV = rbUV;
    bottomBlendUV = bbUV;
}