#include "ShaderUtil.h"

Shader::Shader(const fs::path& vShaderPath, const fs::path& fShaderPath)
{
	std::string vShaderCode, fShaderCode;
	std::ifstream vShaderFile, fShaderFile;
	
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vShaderPath.string(), std::ifstream::in);
		fShaderFile.open(fShaderPath.string(), std::ifstream::in);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();
		
		vShaderCode = vShaderStream.str();
		fShaderCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}
	const char* vShaderCodeC = vShaderCode.c_str();
	const char* fShaderCodeC = fShaderCode.c_str();
	unsigned int vertex, fragment;
	int success = 0;
	char infoLog[512]{};

	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCodeC, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCodeC, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const
{
	int location = -1;
	if ((location = glGetUniformLocation(ID, name.c_str())) != -1)
	{
		glUniform1i(location, value);
	}
}

void Shader::setFloat(const std::string& name, float value) const
{
	int location = -1;
	if ((location = glGetUniformLocation(ID, name.c_str())) != -1)
	{
		glUniform1f(location, value);
	}
}

void Shader::setInt(const std::string& name, int value) const
{
	int location = -1;
	if ((location = glGetUniformLocation(ID, name.c_str())) != -1)
	{
		glUniform1f(location, value);
	}
}

void Shader::destroy()
{
	glDeleteProgram(ID);
}