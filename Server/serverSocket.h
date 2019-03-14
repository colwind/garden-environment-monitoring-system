#ifndef _SERVERSOCKET_H_
#define _SERVERSOCKET_H_
#include "except.h"
using namespace std;

/*
   服务器配置的类
*/


class ServerSocket{
    private:
		int m_sockfd;//服务器套接字

	public:
		//自定义构造函数
		ServerSocket(const string& ip,short port) throw (SocketException);

		//响应客户端请求的函数
		void acceptClient(void) throw (SocketException);

};
#endif
