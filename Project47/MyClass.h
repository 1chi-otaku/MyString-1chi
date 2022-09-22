#pragma once
#include <iostream>;
using namespace std;
class MyString {
	char* String;
	int Length;
	static int Count;
public:
	MyString(); // Конструкторы по умолчанию.
	MyString(unsigned int);
	MyString(const char*);
	MyString(initializer_list <char> a) { // Списковая инициализация.

		Length = a.size();
		String = new char[Length];

		for (auto i = a.begin(); i != a.end(); i++)
		{
			*String = *i;
			String++;
		}
		String -= Length;

		Count++;

	} 
	MyString(const MyString&); //Конструктор копирования
	~MyString(); // Деструктор.
	MyString(MyString&& obj2); // Конструктор переноса.
	void MyStrCpy(const MyString& obj); //Методы копирования строк.
	void MyStrCpy(const char* string, int size);
	void MyStrCat(MyString& b); // Метод конкатенации.
	void MyDelChr(char c); // Метод удаление символа со строки.
	void Init(); // Метод инициализации строки с клавиатуры.
	void Print(); // Метод вывода строки.
	int MyStrLen(); //Методы возврата длины строки
	int MyStrLen(const char* string);
	int MyChr(char c); // Метод, возвращающий индекс символа в строке, в противном случае -1.
	int MyStrCmp(MyString& b); // Метод сравнения строк.
	bool MyStrStr(const char* str); // Метод поиска подстроки в строке.
	static int GetCount(); // Геттер получения статического поля Count, указывающего на кол-во созданных объектов класса MyString.
	void operator()()const;
	MyString& operator=(const MyString& obj); // Перегрузка оператора присваивания.
	MyString& operator=(MyString&& obj2);
	char operator[](int index); // Перегрузка []
	operator int()const { //Перегрузка преобразования int
		return Length;
	}
	operator const char* ()const { //Перегрузка преобразования char*
		return String;
	}


};