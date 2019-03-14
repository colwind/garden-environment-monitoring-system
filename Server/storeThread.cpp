#include "storeThread.h"
#include "data.h"
#include "logBuffer.h"

//实现构造函数
StoreThread::StoreThread(LogDao& dao):m_dao(dao){}

//实现接口中的函数run
void StoreThread::run(void) throw (ThreadException){
	//定义数据对象
	SensorData log;
	for ( ; ; ){
		//从缓冲池中取出数据
		g_LogBuffer >> log;
		try {
			//将数据写入文件或者数据库中
			m_dao.insert(log);
		}catch (DBException ex){
			cout << ex.what() << endl;
		}
	}
}
