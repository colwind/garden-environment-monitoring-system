CC = g++ #指定c++的编译器
RM = rm -rf #指定删除指令
CFLAGS = -c -Wall #指定预编译的参数选项 -Wall 编译时显示所有警告信息
Server:main.o fileDao.o mysqlDao.o logBuffer.o logThread.o storeThread.o clientThread.o serverSocket.o server.o
# $(CC) $^ -lpthread -o $@  #由依赖文件生成目标文件
	$(CC) $^ -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -lpthread -lclntsh -lnsl -o $@
main.o:main.cpp
	$(CC) $(CFLAGS) $^
fileDao.o:fileDao.cpp
	$(CC) $(CFLAGS) $^
mysqlDao.o:mysqlDao.cpp
	$(CC) $(CFLAGS) $^
logBuffer.o:logBuffer.cpp
	$(CC) $(CFLAGS) $^
logThread.o:logThread.cpp
	$(CC) $(CFLAGS) $^
storeThread.o:storeThread.cpp
	$(CC) $(CFLAGS) $^
clientThread.o:clientThread.cpp
	$(CC) $(CFLAGS) $^
serverSocket.o:serverSocket.cpp
	$(CC) $(CFLAGS) $^
server.o:server.cpp
	$(CC) $(CFLAGS) $^
clean:
	$(RM) *.o *.*.gch .*.*.swp


