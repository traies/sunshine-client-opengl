// sunshine-client-opengl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include "..\easyloggingpp\easylogging++.h"
#include "include\client.h"
#include "include\render_gl.h"
#include "RendererWindow.h"
#include "InputCommand.h"

#pragma comment(lib, "Ws2_32.lib")

INITIALIZE_EASYLOGGINGPP

static void GlfwErrorCallback(int error, const char * msg)
{
	LOG(ERROR) << "GLFW failed, error: " << msg;
	return;
}

int main(int argc, const char * argv[])
{
	if (argc < 2) {
		LOG(ERROR) << "Missing parameters. Usage: <port> <codec>";
		return 1;
	}
	if (!glfwInit()) {
		LOG(ERROR) << "Failed glfwInit";
		return 1;
	}
	LOG(INFO) << "Glfw started";
	
	//	Setting error callback
	glfwSetErrorCallback(GlfwErrorCallback);

	// Set up OpenGL
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	int port = atoi(argv[1]);

	//	Set up RenderWindow
	RendererWindow renderWindow (1920, 1080, "Sunshine opengl client", port);
	
	//	Start render Loop
	renderWindow.Render();
    return 0;
}

