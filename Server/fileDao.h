#ifndef _FILEDAO_H_
#define _FILEDAO_H_
#include "logDao.h"
#include<fstream>
using namespace std;
/*
 将通信数据写入文件的类
 */

class FileDao:public LogDao{

	private:
		ofstream m_ofs;//文件流

	public:
		//构造函数
		FileDao(const string& path);

		void insert(const SensorData& log) throw (DBException);
		//析构函数
		~FileDao(void);
};
#endif
