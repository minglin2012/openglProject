#version 120

attribute vec3 position;

void main()
{
// 传递一个顶点信息到光栅化阶段使用
	gl_Position = vec4(position,1.0);
}

