/*
 *
 *声明服务器异常的相关类
 */

#ifndef _EXCEPT_H_
#define _EXCEPT_H_
#include <string>
#include <exception>
using namespace std;

//定义异常类
class ServerException:public exception{
	private :
		string m_msg;


	public:
		ServerException(void):m_msg("服务器异常！"){};
		ServerException(const string& msg):m_msg("服务器异常！"){
			m_msg += msg;
			m_msg += "!";
		}

		//析构函数
		~ServerException(void) throw(){}

		//输出异常消息函数
		const char* what(void) const throw(){
			return m_msg.c_str();
		}
};

class SocketException:public ServerException{
	public:
		SocketException(void):ServerException("Socket错误！"){}
		SocketException(const string& msg):ServerException(msg){}
};

class DBException:public ServerException{
	public:
		DBException(void):ServerException("数据库错误！"){}
		DBException(const string& msg):ServerException(msg){}
};

class SendException:public ServerException{
	public:
		SendException(void):ServerException("数据库发送数据错误！"){}
		SendException(const string& msg):ServerException(msg){}
};

class ThreadException:public ServerException{
	public:
		ThreadException(void):ServerException("线程执行错误！"){}
		ThreadException(const string& msg):ServerException(msg){}
};

#endif
