/*
 定义通信数据的类
 */
#ifndef _DATA_H_
#define _DATA_H_
#include <iostream>
#include <unistd.h>
using namespace std;

//通信数据
typedef struct SensorData{
  char node[17];//节点地址
  char device[3];//设备地址
  char transtype[3];//数据传输方式：主动上报，查询应答
  char startaddr[5];//起始地址
  char bytecount[3];//字节计数
  char temperature[9];///温度
  char humidity[9];//湿度
  char illuminance[9];//光照度
  char solitemperature[9];//土壤温度
  char soliwater[9];//土壤水分
  char voltage[9];//设备电量
  char checkbit1[5];//校验码1
  char checkbit2[5];//校验位2


  //定义输出运算符重载
  friend ostream& operator << (ostream& os,const SensorData log){
       return os << log.node << ","<<log.device << "," <<
		   log.transtype << "," << log.startaddr << "," <<
		   log.bytecount << "," << log.temperature << "," <<
		   log.humidity << "," << log.illuminance << "," <<
		   log.solitemperature << "," << log.soliwater << "," <<
		   log.voltage << "," <<log.checkbit1 << "," << log.checkbit2;
  }

}SensorData;


#endif
