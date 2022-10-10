#pragma once
#include<iostream>
using namespace std;
class Exception
{
protected:
	char message[128];
public:
	Exception() {
		strcpy_s(message, strlen("ERROR") + 1, "ERROR");
	}
	Exception(const char* mess) {
		strcpy_s(message, strlen(mess) + 1, mess);
	}
	virtual void Print() {
		cout << message << endl;
	}
};
class MyStrCatException:public Exception
{
public:
	MyStrCatException() {};
	MyStrCatException(const char* mess) :Exception(mess) {}
	void Print() {
		cout << "MyStrCatException.\n";
		cout << message << endl;
	}
};

class MyStrCpyException :public Exception
{
public:
	MyStrCpyException() {};
	MyStrCpyException(const char* mess) :Exception(mess) {}
	void Print() {
		cout << "MyStrCpyException.\n";
		cout << message << endl;
	}
};

class MyStrPrintException :public Exception
{
public:
	MyStrPrintException() {};
	MyStrPrintException(const char* mess) :Exception(mess) {}
	void Print() {
		cout << "MyStrPrintException.\n";
		cout << message << endl;
	}
};