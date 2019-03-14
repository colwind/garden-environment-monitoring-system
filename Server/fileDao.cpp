#include "fileDao.h"
#include <iostream>
using namespace std;
//实现构造函数
FileDao::FileDao(const string& path){
	cout << "打开数据文件开始..." << endl;
	m_ofs.open(path.c_str(),ios::app);//以追加内容的方式打开 ios::binary二进制文件  默认是以ASCII
	if (!m_ofs){
		throw DBException("打开数据文件失败！");	
	}
	cout << "打开数据文件结束！" << endl;
}
//实现虚构函数
FileDao::~FileDao(void){
	cout << "关闭数据文件开始..." << endl;
	m_ofs.close();
	cout << "关闭数据文件结束！" << endl;
}
//实现将通信数据写入文件
void FileDao::insert(const SensorData& log) throw (DBException){
	cout << "写入通信数据开始..." << endl;
	m_ofs << log << endl;
	cout << "写入通信数据结束！" << endl;
}
