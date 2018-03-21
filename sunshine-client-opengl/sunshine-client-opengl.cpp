// sunshine-client-opengl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GLFW\glfw3.h>
#include "..\easyloggingpp\easylogging++.h"
#include "include\client.h"
#include "include\render_gl.h"
#include "RendererWindow.h"

INITIALIZE_EASYLOGGINGPP

static void GlfwErrorCallback(int error, const char * msg)
{
	LOG(ERROR) << "GLFW failed, error: " << msg;
	return;
}

int main()
{
	if (!glfwInit()) {
		LOG(ERROR) << "Failed glfwInit";
	}
	LOG(INFO) << "Glfw started";
	
	//	Setting error callback
	glfwSetErrorCallback(GlfwErrorCallback);

	//	Set up RenderWindow
	auto renderWindow = std::make_unique<RendererWindow>(640, 480, "Sunshine opengl client");
	
	//	Start render Loop
	renderWindow->Render();
	glfwTerminate();
    return 0;
}

