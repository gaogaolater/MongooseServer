// ServerConsole.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HttpServer.h"
#include "mongoose.h"

std::string handle_fun1(http_message* http_req)
{
	return "{code:'api/fun1'}";
}

int main()
{
	std::string port = "7998";
	auto http_server = std::shared_ptr<HttpServer>(new HttpServer);
	http_server->Init(port);
	// add handler
	http_server->AddHandler("/api/fun1", handle_fun1);
	http_server->Start();
}