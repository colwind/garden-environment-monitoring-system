#include <iostream>
#include "fileDao.h"
#include "mysqlDao.h"
#include "server.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/*
应用程序的入口
   */
//检查用户输入是否是数字
bool check (const char *p){
	if (p == NULL){
		return 0;
	}
	else{
		while (*p != '\0'){
			if (*p <= '9' && *p++ >= '0')
				continue;
			else
				return 0;
		}
	}
	return 1;
}

//菜单
void menu(void){
	while (1)
	{
		cout << "************************************\n" << endl;
		cout << "----温室花卉环境信息智能监测系统----\n" << endl;
		cout << "请选择保存通信数据的方式：\n" << endl;
		cout << "[1] 写入文件\n" << endl;
		cout << "[2] 写入数据库\n" << endl;
		cout << "[6] 清屏\n" << endl;
		cout << "[0] 退出\n" << endl;
		cout << "[ctrl + c]强行终止程序\n" << endl;
		cout << "************************************\n" << endl;
		string choice;
		cout << "请选择： "<< endl;
		getline(cin,choice);
		//cin >> choice;
		if (choice.length()>1 || !check(choice.c_str())){
			cout << "没有这个选项，请重新选择...\n" << endl;
			cout << "请输入一个数字： 如 0 1 2 6：\n" << endl;
		}
		else{
			//判断范围
			int ch = atoi(choice.c_str());
			switch (ch){
				case 1:
					try{
						//写入文件
						FileDao dao("./SensorData.dat");
						//实例化一个服务器
						Server se(dao,"",8888);
						se.dataMine();
					}catch (ServerException ex){
						cout << ex.what() << endl;
					}
					break;
				case 2:
					try{
						//写数据库
						MysqlDao dao;
						Server se(dao,"",8888);
						se.dataMine();
					}catch (ServerException ex){
						cout << ex.what() << endl;
					}
					break;
				case 6:
					system("clear");
					break;
				case 0:
					return;
				default:
					return;
			}
		}
	}
}
int main (int argc,char *argv[]){
	//调用菜单
	menu();

	return 0;
}
