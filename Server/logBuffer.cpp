#include "logBuffer.h"


//实现构造函数
LogBuffer::LogBuffer(void){
	//初始化成员变量
	pthread_mutex_init(&m_mutex,0);
	pthread_cond_init(&m_cond,0);

}
//实现将数据压入缓冲池 
LogBuffer& LogBuffer::operator << (const SensorData& log){
	cout << "压入通信数据至缓冲池开始！" << endl;

	//加锁
	pthread_mutex_lock(&m_mutex);
	//将数据放入list中:从尾部压入数据
	m_logs.push_back(log);
	//唤醒存储线程
	pthread_cond_signal(&m_cond);
	//释放锁
	pthread_mutex_unlock(&m_mutex);
	cout << "压入通信数据至缓冲池结束！" << endl;
	return *this;
}

//实现从数据缓冲池中取出数据
LogBuffer& LogBuffer::operator >>(SensorData& log){
	cout << "从缓冲池中弹出数据开始..." << endl;
	//加锁
	pthread_mutex_lock(&m_mutex);
	//如果没取到
	if (m_logs.empty()){
		//阻塞存储线程
		pthread_cond_wait(&m_cond,&m_mutex);
	}
	//取出一条数据
	log = m_logs.front();//从头部弹出数据
	//把已经取得的数据从链表中删除
	m_logs.pop_front();
	//释放锁
	pthread_mutex_unlock(&m_mutex);
	cout << "从缓冲池中弹出数据结束！" << endl;
	return *this;
}
//定义一个能被外部模块使用的LoogBuffer对象
LogBuffer g_LogBuffer;
