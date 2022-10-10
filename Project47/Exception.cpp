#include "Exception.h"

Exception::Exception()
{
}

Exception::Exception(const char* mess)
{
	strcpy_s(message,strlen(mess)+1,mess);
}

void Exception::Print()
{
	cout << message << endl;
}
