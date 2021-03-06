uniform float time;
vec4 _r0004;
void main()
{
    vec2 Translation1,Translation2,Translation3,Translation4;
    Translation1 = vec2(time, 0.0);
    Translation2 = vec2(time*2, 0.0);
    Translation3 = vec2(time*3, 0.0);
    Translation4 = vec2(time*4, 0.0);
    _r0004 = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_FrontColor = gl_Color;
    gl_Position = _r0004;
    gl_TexCoord[0] = gl_Vertex;
    gl_TexCoord[1].xy = gl_MultiTexCoord0.xy + Translation1*2.0;
    gl_TexCoord[2].xy = gl_MultiTexCoord0.xy*2.0 + Translation2*4.0;
    gl_TexCoord[3].xy = gl_MultiTexCoord0.xy*4.0 + Translation3*2.0;
    gl_TexCoord[4].xy = gl_MultiTexCoord0.xy*8.0 + Translation4;
    gl_TexCoord[5] = _r0004;   
    return;
} 
