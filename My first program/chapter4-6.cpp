#include <iostream>

//class MyString {
//	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
//	int string_length; // ���ڿ� ����
//
//	int memory_capacity; // ���� �Ҵ�� �뷮
//
//public:
//	// capacity ��ŭ �̸� �Ҵ�
//	MyString(int capacity);
//
//	// ���ڿ��κ��� ����
//	MyString(const char* str);
//
//	// ���� ������
//	MyString(const MyString& str);
//
//	~MyString();
//
//	int length() const;
//
//	void DoSomethingWithString(MyString s) {
//		// Do Someting..
//	}
//
//};
//
//MyString::MyString(int capacity) {
//	string_content = new char[capacity];
//	string_length = 0;
//	memory_capacity = capacity;
//	std::cout << "Capacity : " << capacity << std::endl;
//}
//
//MyString::MyString(const char* str) {
//	string_length = 0;
//	while(str[string_length++]) {}
//
//	string_content = new char[string_length];
//	memory_capacity = string_length;
//
//	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
//}
//
//MyString::MyString(const MyString& str) {
//	string_length = str.string_length;
//	memory_capacity = str.string_length;
//	string_content = new char[string_length];
//
//	for (int i = 0; i != string_length; i++) {
//		string_content[i] = str.string_content[i];
//	}
//}
//
//MyString::~MyString() { delete[] string_content; }
//
//int MyString::length() const { return string_length; }
//
//int main() { MyString s(3); }

//class A {
//	mutable int data_;
//
//public:
//	A(int data) : data_(data) {}
//	void DoSomething(int x) const {
//		data_ = x; // mutable int data_; �� ��쿡�� -> Error!
//	}
//
//	void PrintDate() const { std::cout << "data: " << data_ << std::endl; }
//};
//
//int main() {
//	A a(10);
//	a.DoSomething(3);
//	a.PrintDate();
//}