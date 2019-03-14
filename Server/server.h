#ifndef _SERVER_H_
#define _SERVER_H_
#include "serverSocket.h"
#include "logDao.h"
#include "storeThread.h"
using namespace std;

/*
启动服务器的类
*/

class Server{

	private:
		StoreThread m_store;//存储数据类的对象
		ServerSocket m_socket;//服务器配置类的对象

    public:
        //自定义构造函数
		Server(LogDao& dao,const string& ip,short port) throw (ServerException);

		//采集客户端数据的函数
		void dataMine(void) throw (ServerException);

};

#endif
