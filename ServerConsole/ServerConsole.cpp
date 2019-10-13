// ServerConsole.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HttpServer.h"
#include "mongoose.h"
using namespace std;

string handle_fun1(http_message* http_req)
{
	char n1[100], n2[100];
	mg_get_http_var(&http_req->query_string, "a",n1, sizeof(n1));
	mg_get_http_var(&http_req->query_string, "b", n2, sizeof(n2));
	string n1str = n1;
	return "{code:'api/fun1'}";
}

int main()
{
	string port = "7998";
	auto http_server = shared_ptr<HttpServer>(new HttpServer);
	http_server->Init(port);
	// add handler
	http_server->AddHandler("/api/fun1", handle_fun1);
	http_server->Start();
}