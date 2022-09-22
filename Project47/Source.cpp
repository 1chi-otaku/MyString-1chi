#include <iostream>
#include "MyClass.h"
using namespace std;

int main() {
	MyString str ("Hello!");
	


	MyString str2 = move(str);

	str2();


	MyString str3{ 'H', 'e', 'l', 'l', 'o', '!', '\0' };

	str3();
	return 0;
}