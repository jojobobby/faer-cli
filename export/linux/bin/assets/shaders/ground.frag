#version 400

precision lowp float;

in vec2 baseUV;
in vec2 uv;
in vec2 leftBlendUV;
in vec2 topBlendUV;
in vec2 rightBlendUV;
in vec2 bottomBlendUV;

layout (location = 0) out vec4 resultColor;

uniform vec2 leftMaskUV;
uniform vec2 topMaskUV;
uniform vec2 rightMaskUV;
uniform vec2 bottomMaskUV;
uniform sampler2D sampler;

void main() {
    vec4 result = texture(sampler, uv + baseUV);

    if (leftBlendUV.x >= 0 && texture(sampler, leftMaskUV + baseUV).a == 1)
        result = texture(sampler, leftBlendUV + baseUV);
    if (topBlendUV.x >= 0 && texture(sampler, topMaskUV + baseUV).a == 1)
        result = texture(sampler, topBlendUV + baseUV);
    if (rightBlendUV.x >= 0 && texture(sampler, rightMaskUV + baseUV).a == 1)
        result = texture(sampler, rightBlendUV + baseUV);
    if (bottomBlendUV.x >= 0 && texture(sampler, bottomMaskUV + baseUV).a == 1)
        result = texture(sampler, bottomBlendUV + baseUV);
    
    resultColor = result;    
}