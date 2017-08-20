#include "Shader.h"
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>

static GLuint CreateShader(const std::string& text, GLenum shaderType);

static void CheckShaderError(GLuint shader, GLuint flags, bool isProgram, const std::string& errorMessage);

static std::string LoadShader(const std::string& fileName);


Shader::Shader(const std::string& fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"),GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"),GL_FRAGMENT_SHADER);

	for (unsigned int i=0;i<NUM_SHADERS;i++)
	{
		glAttachShader(m_program,m_shaders[i]);
	}
	glLinkProgram(m_program);
	CheckShaderError(m_program,GL_LINK_STATUS,true,"Error: Pragma Link Failure");

	glValidateProgram(m_program);
	CheckShaderError(m_program,GL_VALIDATE_STATUS,true,"Error: Pragma Validate Failure");
}

Shader::~Shader()
{
	for (unsigned int i=0;i<NUM_SHADERS;i++)
	{
		glDetachShader(m_program,m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}

void Shader::Bind()
{
	glUseProgram(m_program);
}


GLuint CreateShader(const std::string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if(shader == 0)
	{
		std::cerr <<"Error: shader creating failure"<<std::endl;
	}

	const GLchar*  shaderSourceString[1];
	GLint shaderSourceStringLength[1];
	shaderSourceString[0]= text.c_str();
	shaderSourceStringLength[0] = text.length();

	glShaderSource(shader,1,shaderSourceString,shaderSourceStringLength);
	glCompileShader(shader);

	CheckShaderError(shader,GL_COMPILE_STATUS,false, "Error: shader compilation failed");
	return shader;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = {0 };
	if(isProgram)
	{
		glGetProgramiv(shader,flag,&success);

	}
	else
	{
		glGetShaderiv(shader,flag,&success);
	}

	if(success == GL_FALSE)
	{
		if(isProgram)
		{
			glGetProgramInfoLog(shader,sizeof(error),NULL,error);
		}
		else
		{
			glGetShaderInfoLog(shader,sizeof(error),NULL,error);
		}
		std::cerr<<errorMessage<<":'"<<error<<"'"<<std::endl;
	}
}

std::string LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;

	if(file.is_open())
	{
		while(file.good())
		{
			getline(file,line);
			output.append(line + "\n");
		}

	}
	else
	{
		std::cerr <<"Unable to load shader:"<<fileName<<std::endl;

	}
	return output;
}
