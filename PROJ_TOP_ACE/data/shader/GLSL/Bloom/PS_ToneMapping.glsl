#version 120
varying vec2 TexCoord0;
uniform sampler2DRect _texSrc1;
void main()
{
    gl_FragColor = vec4(1.0,1.0,1.0,texture2DRect(_texSrc1, TexCoord0.xy).x*1.2);
	//gl_FragColor = texture2DRect(_texSrc1, TexCoord0.xy);
    return;
}