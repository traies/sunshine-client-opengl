// sunshine-client-opengl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UDPClient.h"
#include <GLFW\glfw3.h>
#include "..\easyloggingpp\easylogging++.h"
#include "include\client.h"
#include "include\render_gl.h"
#include "RendererWindow.h"
#include <cereal\archives\binary.hpp>

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
	
	//	Start Controller UDPClient
	UDPClient client("127.0.0.1", 1235);

	//	Send input commands on this thread.
	std::thread thread([&] {
		boost::asio::streambuf buf;
		std::ostream os(&buf);
		cereal::BinaryOutputArchive archive(os);
		int64_t val = 347;
		archive(val);
		while (true) {
			client.send(buf);
			Sleep(1000);
		}
	});

	//	Start render Loop
	renderWindow->Render();
	renderWindow.release();
    return 0;
}

