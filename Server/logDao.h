#ifndef _LOGDAO_H_
#define _LOGDAO_H_
#include "except.h"
#include "data.h"

/*
处理数据的接口
*/

class LogDao{

	public:
		//纯虚函数
		virtual void insert(const SensorData& log) throw (DBException) = 0;

		//虚析构函数
		virtual ~LogDao(void){}

};
#endif
