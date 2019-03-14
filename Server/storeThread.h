#ifndef _STORETHREAD_H_
#define _STORETHREAD_H_
#include "logThread.h"
#include "logDao.h"
using namespace std;

/*
 存储数据的类:实现处理数据的线程的接口
*/

class StoreThread:public LogThread{
    private:
		LogDao& m_dao;//实现ＬｏｇＤａｏ接口的类的对象

	public:
		//构造函数
		StoreThread(LogDao& dao);
		
		//虚函数重写：实现接口中的函数
		void run(void) throw (ThreadException);

	  
};

#endif
