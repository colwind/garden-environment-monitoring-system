#include "serverSocket.h"
#include "clientThread.h"

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
using namespace std;
//实现构造函数
ServerSocket::ServerSocket(const string& ip,short port) throw (SocketException)
{
	cout << "启动服务器开始..." << endl;
	//1.创建服务器Socket
	m_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (m_sockfd == -1){
		throw SocketException("创建服务器socket失败！");
	}
	//允许重用本地地址
	int reuse = 1;
	if (-1 == setsockopt(m_sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse))){
		throw SocketException("设置服务器socket地址重用失败！");
	}
	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	//将一个点分的ip地址转换成32位无符号整数
	addr.sin_addr.s_addr = ip.empty() ? INADDR_ANY : inet_addr(ip.c_str());

	//3.绑定
	if (-1 == bind(m_sockfd,(struct sockaddr *)&addr,sizeof(addr)))	{
		throw SocketException("绑定服务器socket失败！");
	}

	//4.监听
	if (-1 == listen(m_sockfd,1024))	{
		throw SocketException("服务器监听失败！");
	}
	cout << "启动服务器结束！" << endl;
}
//响应客户请求
void ServerSocket::acceptClient(void) throw (SocketException){
	cout << "等待客户端连接..." << endl;
	
	for (;;){
		//准备通信地址：用来保存客户端的地址
		struct sockaddr_in addrcli;
		socklen_t len = sizeof(addrcli);//不能够给零,零是得不到客户端地址
		//介乎搜客户度啊连接
		int connfd = accept(m_sockfd,(struct sockaddr*)&addrcli,&len);//返回的是客户端套接字
		if(-1 == connfd){
			throw SocketException("接受客户端连接失败！");
		}
		//new一个客户端线程的类的对象，处理后续的通信（接收数据）
		(new ClientThread(connfd)) -> start();//启动启动接收线程


	}	
}


