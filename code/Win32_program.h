#pragma once

// Choose the target renderer
#define USE_OPENGL_2
//#define USE_OPENGL_1
//#define USE_D3D

// This is the Program class that is called by Application
class Program
{
public:
	static int main(const std::vector<std::string> &args);
};
