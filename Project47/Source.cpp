#include <iostream>
#include "Exception.h"
#include "MyClass.h"
using namespace std;

int main() {
	try {
		MyString stri;
		stri();

	}
	catch(Exception* a) {
		a->Print();
		delete a;
	}

	return 0;
}