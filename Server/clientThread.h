#ifndef _CLIENTTHREAD_H_
#define _CLIENTTHREAD_H_
#include "logThread.h"
/*
客户端线程处理类：接受客户端发送的数据
 */
class ClientThread:public LogThread{
    private:
		int m_connfd;//客户端套接字
        
	public:
		//构造函数
		ClientThread(int connfd);

		//实现接口的函数
	    void run(void) throw (ThreadException,SendException);

};
#endif
