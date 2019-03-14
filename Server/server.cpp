#include "server.h"
//自定义的构造函数:用参数初始化列表来给成员变量赋值
Server::Server(LogDao& dao,const string& ip,short port)
	throw (ServerException):m_store(dao),m_socket(ip,port){}





	//采集客户端数据
	void Server::dataMine(void) throw (ServerException){
		try {

			//1.启动存储线程，准备存储数据
			m_store.start();

			//2.启动客户端线程，准备接受数据
			m_socket.acceptClient();
		}catch(ServerException){
			throw;//抛出异常
		}

	}
