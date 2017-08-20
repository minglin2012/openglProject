#version 120

uniform sampler2D diffuse;

void main()
{
//指定片元着色器使用的颜色信息
	//gl_FragColor = vec4(1.0f,0.0f,0.0f,1.0f);
	gl_FragColor = texture2D(diffuse,vec2(0.2,0.2f));
	
}
