#ifndef _LOGTHREAD_H_
#define _LOGTHREAD_H_
#include "except.h"
using namespace std;
/*处理通信数据的抽象类：接口*/

class LogThread{
	public :
		//虚析构函数
		virtual ~LogThread(void){};

		//启动线程的函数
		void start (void) throw(ThreadException);

		//纯虚函数
		virtual void run(void) = 0;

	private:
		static void* run(void* arg);

};

#endif
