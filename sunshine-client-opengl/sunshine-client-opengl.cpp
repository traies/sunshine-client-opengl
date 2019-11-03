// sunshine-client-opengl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	if (argc < 3) {
		LOG(ERROR) << "Missing parameters. Usage: <ip> <port>";
		return 1;
	}
	if (!glfwInit()) {
		LOG(ERROR) << "Failed glfwInit";
		return 1;
	}
	LOG(INFO) << "Glfw started";
	
	//	Setting error callback
	glfwSetErrorCallback(GlfwErrorCallback);

	//	Set up RenderWindow
	RendererWindow renderWindow (1280, 720, "Sunshine opengl client", argv[1], argv[2]);
	
	//	Start render Loop
	renderWindow.Render();
    return 0;
}

