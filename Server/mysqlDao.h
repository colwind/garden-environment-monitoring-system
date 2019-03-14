#ifndef _MYSQLDAO_H_
#define _MYSQLDAO_H_
#include "logDao.h"
#include "/usr/include/mysql/mysql.h"
/*
 将通信数据插入数据库的类
 */
class MysqlDao:public LogDao{
	private:
		char* m_host;//数据库服务器的ip地址
		char* m_user;//登录数据库的帐号
		char* m_pass;//登录密码
		char* m_db;//数据库名称
		int m_port;//连接数据库的端口：mysql：3306
		const char* sqlcmd;//语句

		MYSQL mysql;//mysql数据库对象
		MYSQL_RES* res;//结果集
		MYSQL_ROW row;//数据行对象
	public:
		//构造函数
		MysqlDao(void);
		//析构函数
		~MysqlDao (void);
		//实现接口中的函数
		void insert(const SensorData& log) throw (DBException);

		//定义以下私有函数
	private:
		//连接数据库函数
		void connectDB(void) throw (DBException);
		//插入数据函数
		void insertData(const SensorData& log)throw (DBException);
};
#endif
