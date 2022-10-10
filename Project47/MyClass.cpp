#include "MyClass.h"
#include <iostream>
#include "Exception.h"
using namespace std;

MyString::MyString() {
	Count++;
	Length = 80;
	String = nullptr;
}
MyString::MyString(unsigned int size) {
	Count++;
	Length = size;
	String = new char[Length + 1];
}
MyString::MyString(const char* string) {
	Count++;
	Length = MyStrLen(string);
	String = nullptr;
	this->MyStrCpy(string, Length);
}


MyString::MyString(const MyString& temp) {
	String = new char[MyStrLen(temp.String) + 1];
	MyStrCpy(temp);
	Length = temp.Length;
	Count++;
}
MyString::~MyString() {
	Count--;
	if (String != nullptr)delete[]String;
}
MyString::MyString(MyString&& obj2)
{
	String = obj2.String;
	obj2.String = nullptr;
	
	Length = obj2.Length;
	obj2.Length = 0;

}
void MyString::MyStrCpy(const MyString& obj) {
	if (this == &obj) {
		throw new MyStrCpyException("The objects are the same!");
	}
	this->Length = obj.Length;
	if (String != nullptr)delete[]this->String;
	this->String = new char[Length + 1];
	for (int i = 0; i < Length; i++)
		this->String[i] = obj.String[i];
	this->String[Length] = '\0';
}
void MyString::MyStrCpy(const char* string, int size) {
	this->Length = size;
	if (String != nullptr)delete[]this->String;
	this->String = new char[size + 1];
	for (int i = 0; i < Length; i++)
		this->String[i] = string[i];
	this->String[Length] = '\0';
}
void MyString::MyStrCat(MyString& b) {
	int AllSize = Length + b.Length; //Определение общего размера двух строк.
	if (AllSize == Length) {
		throw new MyStrCatException("The length of second string is 0.");
	}
	char* temp = new char[Length + 1];
	for (int i = 0; i < Length; i++)	//temp для сохранения строки объекта класса для дальнейшего очищения памяти.
	{
		temp[i] = this->String[i];
	}
	temp[Length] = '\0';
	delete[]String;
	String = new char[AllSize + 2];		// Выделение памяти размером в две строки.
	int i = 0;
	for (i; i < Length; i++)
	{
		this->String[i] = temp[i];
	}for (int j = 0; j < b.Length; j++, i++)	// Циклы, заполняющие новую строку с помощью temp & конкатенирующей строки.
	{
		this->String[i] = b.String[j];
	}
	String[AllSize] = '\0';
	delete[]temp;
	Length = AllSize;

}
void MyString::MyDelChr(char c) {
	int character = 0;					//кол-во символов к удалению.
	char* temp;
	temp = new char[Length + 1];        //temp для сохранения строки объекта класса для дальнейшего очищения памяти.
	for (int i = 0; i < Length; i++) {
		if (String[i] == c) character++;
		temp[i] = String[i];
	}
	temp[Length] = '\0';
	delete[]String;
	String = new char[Length - character + 1];			// Выделение участка памяти для указатель String с учетом удаленных символов.
	for (int i = 0, j = 0; j < Length; j++)
	{
		if (temp[j] == c) {
			continue;
		}												// Заполнения участка памяти с учетом удаленных символов.
		else {
			String[i] = temp[j];
			i++;
		}
	}
	this->String[Length - character] = '\0';
	delete[]temp;
}
void MyString::Init() {
	char buff[80];
	if (String != nullptr) delete[] String;
	cout << "Enter new string: " << endl;
	cin.getline(buff, MyStrLen(buff) + 1);
	String = new char[MyStrLen(buff) + 1];
	this->MyStrCpy(buff, MyStrLen(buff));
}
void MyString::Print() {
	if (String == nullptr) {
		throw new MyStrPrintException("There is no string to print..");
	}
	cout << String << endl;
}
int MyString::MyStrLen() {
	int count = 0;
	for (int i = 0; String[i] != '\0'; i++)
	{
		count++;
	}
	return count;

}
int MyString::MyStrLen(const char* string) {
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
int MyString::MyChr(char c) {
	for (int i = 0; i < Length; i++)
	{
		if (c == this->String[i]) {
			return i;
		}
	}
	return -1;
}
int MyString::MyStrCmp(MyString& b) {
	if (Length == b.Length) return 0;
	else if (Length > b.Length) return 1;
	else return -1;
}
int MyString::GetCount() {
	return Count;
}
bool MyString::MyStrStr(const char* str) {
	int count = 0;
	for (int i = 0, j = 0; i < Length; i++)
	{
		if (this->String[i] == str[j]) {
			j++;
			count++;										//Имея размер подстроки, цикл проверяет, является ли подстрока полной, в позитивном случае возвращает 1.
			if (count == MyStrLen(str)) {
				return 1;
			}
		}
	}
	return 0;
}
char MyString::operator[](int index) {
	if (index >= 0 && index < MyStrLen(String) + 1)
		return String[index];
	return '\0';
	;
}
MyString& MyString::operator=(const MyString& obj){
	if (this == &obj) {
		return *this;
	}
	if (String != nullptr) delete[]String;
	String = new char[MyStrLen(obj.String) + 1];
	Length = obj.Length;
	for (int i = 0; i < MyStrLen(String); i++)
	{
		String[i] = obj.String[i];
	}
	return *this;
}
MyString& MyString::operator=(MyString&& obj2)
{
	if (String != nullptr)delete[]String;
	String = obj2.String;
	obj2.String = nullptr;

	Length = obj2.Length;
	obj2.Length = 0;

	return *this;
}
void MyString::operator()()const {
	if (String == nullptr) {
		throw new MyStrPrintException("There is no string to print..");
	}
	cout << String << "\n" << Length << "\n" << Count << "\n";
}


int MyString::Count = 0;
