void mainImage(out vec4 fragColor, in vec2 u) {
    vec2 R = iResolution.xy, 
         p = (u - 0.5 * R) / R.y + iTime * 0.1,
         n = R-R, 
         N = n,
         q,
         c; 
    mat2 m = mat2(cos(vec4(1,13,35.5,1)));
    
    for (float s = 10.0, j = 0.0; j++ < 10.0; s *= 1.2) {
        p *= m;
        n *= m;
        n += sin(q = p*s + j + n + iTime);
        N += cos(q) / s;
    }
        
    fragColor = vec4(1,2,4,0) * (N.x + N.y + 0.15) * 1.2 + 0.005 / length(N);
}