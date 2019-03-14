#ifndef _LOGBUFFER_H_
#define _LOGBUFFER_H_
#include "data.h"
#include <pthread.h>
#include <list>
/*
   数据缓冲池的类
   */
class LogBuffer{
    
	//定义私有变量
	private:
		pthread_mutex_t m_mutex;//线程互斥量对象
		pthread_cond_t m_cond;//线程条件变量对象
		list<SensorData> m_logs;//数据缓冲池：链表

	public:
		LogBuffer(void);
	    
	    //数据压入缓冲池:输出运算符重载
	    LogBuffer& operator << (const SensorData& log);
       
		//从缓冲池中取出数据：输入运算符重载
		LogBuffer& operator >> (SensorData& log);

};

//声明一个能被其它模块调用的LogBuffer对象
extern LogBuffer g_LogBuffer;
#endif
