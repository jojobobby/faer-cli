#version 400

precision lowp float;

in vec2 uv;

layout (location = 0) out vec4 resultColor;

uniform vec2 texelSize;
uniform float alphaMult;
uniform sampler2D sampler;

void main() {
    vec4 pixel = texture(sampler, uv);

    pixel.a *= alphaMult;

    if (texelSize.x != 0 && pixel.a < 1.0) {
        float alpha = texture(sampler, uv - texelSize).a;
        alpha += texture(sampler, vec2(uv.x - texelSize.x, uv.y + texelSize.y)).a;
        alpha += texture(sampler, vec2(uv.x + texelSize.x, uv.y - texelSize.y)).a;
        alpha += texture(sampler, uv + texelSize).a;

        if (alpha > 0)
            pixel = vec4(0.0, 0.0, 0.0, 1.0);
    }
        
    resultColor = pixel;
}