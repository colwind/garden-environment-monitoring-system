#include "clientThread.h"
#include "logBuffer.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>


//实现构造函数
ClientThread::ClientThread(int connfd):m_connfd(connfd){}

//实现接口中的run方法
void ClientThread::run(void) throw (ThreadException,SendException){
	//定义一个数据对象
	SensorData log;
	//定义一个非常大的数字
	unsigned long long big;
	for (big=0 ; ; big++){
		//定义一个已经收到的字节数
		size_t rlen;
		//size_t len;表示剩下未收的数据
		for (size_t len = sizeof(log); len ; len-=rlen){
			//<0，表示客户端已经断开    =0，数据收完
			if ((rlen = recv(m_connfd,(char *)&log + (sizeof(log) - len) , len , 0)) <= 0){
				goto escape;
			}
		}
		//将收到的数据保存至数据缓冲池中
		g_LogBuffer << log;
		//将收到的数据发回客户端
//		if (-1 == send(m_connfd,&log,sizeof(log),0)){
//			throw SendException("回复客户端数据失败！");
//		}
//		cout << "server-->client 回复数据成功！" << endl;
	}
escape:
	cout << "收到：" << big << " 条客户端数据！" << endl;
	//关闭客户端套接字
	close(m_connfd);
	//释放客户端线程类的对象
	delete this;
}
