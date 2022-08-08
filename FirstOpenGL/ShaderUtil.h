#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

namespace fs = std::filesystem;

class Shader
{
public:
	unsigned int ID; // the program ID
	// constructor to read and build the shader
	Shader(const fs::path& vShaderPath, const fs::path& fShaderPath);
	// use/activate the shader
	void use();
	// delete shader
	void destroy();
	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
};

#endif