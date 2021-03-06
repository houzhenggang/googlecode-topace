#version 110
#extension GL_ARB_texture_rectangle : enable
varying vec2 TexCoord0;
uniform sampler2DRect BlurTex;
uniform vec2 BlurTexSet;
void main()
{
    vec4 color=vec4(0.0,0.0,0.0,0.0);
    color += texture2DRect(BlurTex,TexCoord0.xy+BlurTexSet*5.0) * 0.1;
    color += texture2DRect(BlurTex,TexCoord0.xy+BlurTexSet*4.0) * 0.22;
    color += texture2DRect(BlurTex,TexCoord0.xy+BlurTexSet*3.0) * 0.358;
    color += texture2DRect(BlurTex,TexCoord0.xy+BlurTexSet*2.0) * 0.523;
    color += texture2DRect(BlurTex,TexCoord0.xy+BlurTexSet) * 0.843;
    color += texture2DRect(BlurTex,TexCoord0.xy );
    color += texture2DRect(BlurTex,TexCoord0.xy-BlurTexSet) * 0.843;
    color += texture2DRect(BlurTex,TexCoord0.xy-BlurTexSet*2.0) * 0.523;
    color += texture2DRect(BlurTex,TexCoord0.xy-BlurTexSet*3.0) * 0.358;
    color += texture2DRect(BlurTex,TexCoord0.xy-BlurTexSet*4.0) * 0.22;
    color += texture2DRect(BlurTex,TexCoord0.xy-BlurTexSet*5.0) * 0.1;
    color = color/5.0;
    gl_FragColor = color;
    return;
}
