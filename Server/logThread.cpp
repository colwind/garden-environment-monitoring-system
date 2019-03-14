#include "logThread.h"
#include "pthread.h"
#include <iostream>
using namespace std;
//启动线程
void LogThread::start(void) throw (ThreadException){
	cout << "启动线程开始..." << endl;
	//创建一个新线程
	pthread_t tid;
	if (pthread_create(&tid,0,run,this)){
		throw ThreadException("启动线程失败！");
	}		
	cout << "启动线程结束！" << endl;
}

void* LogThread::run(void* arg){
	//分离当前线程
	pthread_detach(pthread_self());
	//调用真正的run函数，在实现类中已经进行了重写
	static_cast<LogThread*>(arg) ->run();
	return arg;
}
