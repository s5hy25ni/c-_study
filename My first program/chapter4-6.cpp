#include <iostream>

//class MyString {
//	char* string_content; // 문자열 데이터를 가리키는 포인터
//	int string_length; // 문자열 길이
//
//	int memory_capacity; // 현재 할당된 용량
//
//public:
//	// capacity 만큼 미리 할당
//	MyString(int capacity);
//
//	// 문자열로부터 생성
//	MyString(const char* str);
//
//	// 복사 생성자
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
//		data_ = x; // mutable int data_; 의 경우에는 -> Error!
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