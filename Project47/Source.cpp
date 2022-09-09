#include <iostream>
using namespace std;
//Commit
class MyString {
	char* String;
	int Length; 
	static int Count;
public:
	MyString(); // Конструкторы по умолчанию.
	MyString(unsigned int);
	MyString(const char*);
	~MyString(); // Деструктор.
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
	
};
MyString::MyString() {
	Count++;
	Length = 80;
	String = new char[Length + 1];
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
MyString::~MyString() {
	Count--;
	if (String != nullptr)delete[]String;
}
void MyString:: MyStrCpy(const MyString& obj) {
	this->Length = obj.Length;						
	if (String != nullptr)delete[]this->String;
	this->String = new char[Length + 1];
	for (int i = 0; i < Length; i++)
		this->String[i] = obj.String[i];
	this->String[Length] = '\0';
}
void MyString:: MyStrCpy(const char* string, int size) {
	this->Length = size;
	if (String != nullptr)delete[]this->String;
	this->String = new char[size + 1];
	for (int i = 0; i < Length; i++)
		this->String[i] = string[i];
	this->String[Length] = '\0';
}
void MyString::MyStrCat(MyString& b) {
	int AllSize = Length + b.Length; //Определение общего размера двух строк.
	char* temp;
	temp = new char[Length + 1];
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
bool MyString:: MyStrStr(const char* str) {
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


int MyString::Count = 0;

int main() {

	MyString str1;
	MyString str2("Once upon a time");
	str1.Init();
	cout << endl;
	str1.Print();
	str2.Print();
	cout << endl;
	cout << "mystrcpy test: " << endl;
	str1.MyStrCpy(str2);
	str1.Print();
	str2.Print();
	cout << endl;
	cout << "mystrstr test: " << endl;
	cout << "my str str waiting 1 - " << str1.MyStrStr("time");
	cout << endl;
	cout << "mystrchar test: " << endl;
	cout << "my str char waiting 2 - " << str1.MyChr('c');
	cout << endl;
	cout << "my str char waiting -1 - " << str1.MyChr('h');
	cout << endl;
	cout << "mystrlen test: " << endl;
	cout << "mystrlen - " << str1.MyStrLen() << " " << str2.MyStrLen();
	cout << endl;
	cout << "mystrcat test: " << endl;
	str2.Init();
	cout << endl;
	str1.MyStrCat(str2);
	cout << endl;
	str1.Print();
	cout << endl;
	cout << "mydelchr test - a deleted " << endl;
	str1.MyDelChr('a');
	str1.Print();
	cout << endl;
	MyString str3("3");
	MyString str4("4");
	cout << "str compare test" << endl;
	cout << "waiting 0 - " << str3.MyStrCmp(str4);
	cout << endl;
	str3.MyStrCpy("30");
	cout << "waiting 1 - " << str3.MyStrCmp(str4);
	cout << endl;
	str4.MyStrCpy("300");
	cout << "waiting -1 - " << str3.MyStrCmp(str4);
	cout << endl << endl;
	cout << "number of objects - " << MyString::GetCount();

	return 0;
}