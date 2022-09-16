#include <iostream>
#include "MyClass.h"
using namespace std;

int main() {
	MyString str ("Hello!");
	MyString str2("'Sup!");
	str = str2;
	str();

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
	
	return 0;
}