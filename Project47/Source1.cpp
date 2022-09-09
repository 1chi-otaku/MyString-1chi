#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};

Book::Book(const char* n) {
	pages = 0;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Book::Book(const char* n, int p) : Book(n) {
	pages = p;
}
void::Book::Print() {
	cout << name << endl;
	cout << pages << endl;
}
Book::~Book() {
	delete[]name;
}

class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student() :step(0), book(nullptr, 0)
	{
		name = nullptr;
	}
	Student(const char* n, double st, const char* bookName, int bookPages):step(st),book(bookName, bookPages){
		name = new char[strlen(n + 1)];
		strcpy_s(name, strlen(n + 1), n);
	}										
	~Student() {
		
		if(name!=nullptr)delete[]name;

	}
	void Print(){
		cout << name << endl;
		cout << step << endl;
		
	
	}

};
// показать использование объектом в функции main
int main()
{

	Book book1("Booook", 50);
	book1.Print();
	cout << endl;
	Student student1("hell",5.4,"Bookname",5);
	student1.Print();
	
}