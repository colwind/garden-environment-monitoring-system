#include "mysqlDao.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
//实现构造函数
MysqlDao::MysqlDao(void){}


//实现析构函数
MysqlDao::~MysqlDao(void){
	cout << "关闭数据库开始..." << endl;
	mysql_library_end();
	cout << "关闭数据库结束！" << endl;
}
//实现连接数据库
void MysqlDao::connectDB(void) throw (DBException){
	cout << "连接数据库开始..." << endl;
	//1.初始mysql数据库
	mysql_library_init(0,NULL,NULL);
	//2.初始化数据库连接标识符，为连接做准备
	mysql_init(&mysql);
	//3.连接到数据库
	if (!mysql_real_connect(&mysql,m_host,m_user,m_pass,m_db,m_port,NULL,0)){
		cout << "连接mysql数据库出错:" << mysql_error(&mysql) << endl;	
	}
	else{
		cout << "连接maysql数据库成功！" << endl;
	}
	cout << "连接数据库结束！" << endl;
}
//插入数据：实现接口LogDao中的函数
void MysqlDao::insert(const SensorData& log) throw (DBException){
	//连接库前将成员变量（数据库相关）初始化

	//数据库服务器的IP地址
	char host[] = "localhost";//指数据库在本机
	m_host = host;
	//访问数据库的帐号
	char user[] =  "root"; //mysql默认的超级管理员
	m_user = user;
	//访问数据库的密码
	char pass[] =  "123456";
	m_pass = pass;
	//访问数据库名
	char db[] = "SensorDB";
	m_db = db;
	//端口
	m_port = 3306;
	try{
		//1.连接数据库
		connectDB();
		try{
			//2.插入数据库
			insertData(log);
		}catch (DBException){
			throw DBException("插入数据出错！");
		}
	}catch (DBException){
		throw DBException("连接数据库异常！");
	}
	//3.关闭数据库
	mysql_close(&mysql);
	return;
}
//插入数据至库中
void MysqlDao::insertData(const SensorData& log) throw (DBException){
	cout << "向Mysql数据库插入数据开始..." << endl;
	//准备sql语句
	string sql = "insert into SensorDT(node,device,transtype,startaddr,bytecount,temperature,humidity,";
	sql += "illuminance,solitemperature,soliwater,voltage,checkbit1,checkbit2) values(";
	sql += "'"+(string(log.node)  + "','" + string(log.device)      + "','" + string(log.transtype)       + "','" +
			string(log.startaddr) + "','" + string(log.bytecount)   + "','" + string(log.temperature)     + "','" + 
			string(log.humidity)  + "','" + string(log.illuminance) + "','" + string(log.solitemperature) + "','" + 
			string(log.soliwater) + "','" + string(log.voltage)     + "','" + string(log.checkbit1)       + "','" + 
			string(log.checkbit2) + string("')"));
	sqlcmd = sql.c_str();//转换成C语言风格的字符串
	//插入数据
	cout << "插入数据开始..." << endl;
	if (mysql_real_query(&mysql,sqlcmd,(unsigned int)strlen(sqlcmd)) == 0){
		cout << "插入数据成功！" << endl;
	}
	else {
		cout << "插入数据失败：" << mysql_error(&mysql) << endl;
	}
	cout << "向Mysql数据库插入数据结束！" << endl;

	//查询并显示刚插入的数据
	sqlcmd = string("select receiveDate,node,device,transtype,temperature,humidity,illuminance,solitemperature,soliwater,voltage from SensorDT order by sensor_id desc limit 5").c_str();
	int t = 0;
	t = mysql_real_query(&mysql,sqlcmd,(unsigned int)strlen(sqlcmd));
	//返回的结果t为0表示查询成功，非0失败
	if (t){
		cout << "查询数据库失败！" << endl;
	}
	else{
		cout << "查询数据库成功！（取得最新多的5条数据）" << endl;
		res = mysql_store_result(&mysql);//取得查询返回结果集（内存中一张临时表）
		while((row = mysql_fetch_row(res))){//取得一行结果集中的数据
			for (unsigned int i=0;i<mysql_num_fields(res);i++){//取得一行中的所有列
				cout << row[i] << "    ";
			}
			cout << "\n";
		}
		//释放结果集
		mysql_free_result(res);
	}
}

