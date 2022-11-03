//#include <iostream>
//#include <string.h>
//
//class mystring {
//	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
//	int string_length; // ���ڿ� ����
//	int memory_capacity; // ���� �Ҵ�� �뷮
//
//public:
//	// ���� �ϳ��� ����
//		mystring(char c);
//
//	// ���ڿ��κ��� ����
//		mystring(const char* str);
//
//	// ���� ������
//		mystring(const mystring& str);
//
//	~mystring();
//
//	int length() const;
//	int capacity() const;
//	void reserve(int size);
//
//	void print() const;
//	void println() const;
//
//	mystring& assign(const mystring& str);
//	mystring& assign(const char* str);
//
//	char at(int i) const;
//
//	mystring& insert(int loc, const mystring& str);
//	mystring& insert(int loc, const char* str);
//	mystring& insert(int loc, char c);
//
//	mystring& erase(int loc, int num);
//
//	int find(int find_from, mystring& str) const;
//	int find(int find_from, const char* str) const;
//	int find(int find_from, char c) const;
//
//	int compare(const mystring& str) const;
//	int compare2(const mystring* str);
//
//};
//
//mystring::mystring(char c) {
//	string_content = new char[1];
//	string_content[0] = c;
//	memory_capacity = 1;
//	string_length = 1;
//}
//
//mystring::mystring(const char* str) {
//	string_length = strlen(str);
//	memory_capacity = string_length;
//	string_content = new char[string_length];
//
//	for (int i = 0; i != string_length; i++) {
//		string_content[i] = str[i];
//	}
//}
//
//mystring::mystring(const mystring& str) {
//	string_length = str.string_length;
//	memory_capacity = str.string_length;
//	string_content = new char[string_length];
//
//	for (int i = 0; i != string_length; i++) {
//		string_content[i] = str.string_content[i];
//	}
//}
//
//mystring::~mystring() { delete[] string_content; }
//
//int mystring::length() const { return string_length; }
//
//void mystring::print() const {
//	for (int i = 0; i != string_length; i++) {
//		std::cout << string_content[i];
//	}
//}
//
//void mystring::println() const {
//	for (int i = 0; i != string_length; i++) {
//		std::cout << string_content[i];
//	}
//	std::cout << std::endl;
//}
//
//mystring& mystring::assign(const mystring& str) {
//	if (str.string_length > memory_capacity) {
//		// �ٽ� �Ҵ�
//			delete[] string_content;
//
//		string_content = new char[str.string_length];
//		memory_capacity = str.string_length;
//	}
//
//	for (int i = 0; i != str.string_length; i++) {
//		string_content[i] = str.string_content[i];
//	}
//
//	string_length = str.string_length;
//
//	return *this;
//}
//
//mystring& mystring::assign(const char* str) {
//	int str_length = strlen(str);
//	if (str_length > string_length) {
//		delete[] string_content;
//
//		string_content = new char[str_length];
//		memory_capacity = str_length;
//	}
//	for (int i = 0; i != str_length; i++) {
//		string_content[i] = str[i];
//	}
//
//	string_length = str_length;
//
//	return *this;
//}
//
//int mystring::capacity() const { return memory_capacity; }
//
//void mystring::reserve(int size) {
//	if (size > memory_capacity) {
//		char* prev_string_content = string_content;
//
//		string_content = new char[size];
//		memory_capacity = size;
//
//		for (int i = 0; i != string_length; i++) {
//			string_content[i] = prev_string_content[i];
//		}
//
//		delete[] prev_string_content;
//	}
//}
//
//char mystring::at(int i) const {
//	if (i >= string_length || i < 0) {
//		return NULL;
//	}
//	else return string_content[i];
//}
//
//mystring& mystring::insert(int loc, const mystring& str) {
//	// ������ ����� �Է¿� ���ؼ��� ������ �������� ����
//		if (loc < 0 || loc > string_length) return *this;
//
//	if (string_length + str.string_length > memory_capacity) {
//		// ���Ӱ� ���� �Ҵ�
//			if (memory_capacity * 2 > string_length + str.string_length) memory_capacity *= 2;
//			else memory_capacity = string_length + str.string_length;
//
//		char* prev_string_content = string_content;
//		string_content = new char[memory_capacity];
//
//		// insert �Ǵ� �κ� �������� ���� ����
//			int i;
//		for (i = 0; i < loc; i++) {
//			string_content[i] = prev_string_content[i];
//		}
//
//		// ���Ӱ� insert �Ǵ� ���ڿ� ����
//			for (int j = 0; j != str.string_length; j++) {
//				string_content[i + j] = str.string_content[j];
//			}
//
//		// �� ���ڿ��� ������ �޺κ� ����
//			for (; i < string_length; i++) {
//				string_content[str.string_length + i] = prev_string_content[i];
//			}
//
//		delete[] prev_string_content;
//
//		string_length = string_length + str.string_length;
//		return *this;
//	}
//
//	// ���� �ʰ����� �ʴ´ٸ� ���� �����Ҵ� ���ص� ��
//		for (int i = string_length - 1; i >= loc; i--) {
//			string_content[i + str.string_length] = string_content[i];
//		}
//	for (int i = 0; i < str.string_length; i++) {
//		string_content[i + loc] = str.string_content[i];
//
//		string_length = string_length + str.string_length;
//		return *this;
//	}
//}
//
//mystring& mystring::insert(int loc, const char* str) {
//	mystring temp(str);
//	return insert(loc, temp);
//}
//
//mystring& mystring::insert(int loc, char c) {
//	mystring temp(c);
//	return insert(loc, temp);
//}
//
//mystring& mystring::erase(int loc, int num) {
//	// loc�� �� ���� ������ num ���ڸ� ����
//		if (num < 0 || loc < 0 || loc > string_length) return *this;
//
//	if (num > string_length) num = string_length;
//
//	for (int i = loc + num; i < string_length; i++) {
//		string_content[i - num] = string_content[i];
//	}
//
//	string_length -= num;
//	return *this;
//}
//
//int mystring::find(int find_from, mystring& str) const {
//	int i, j;
//	if (str.string_length == 0) return -1;
//	for (i = find_from; i <= string_length - str.string_length; i++) {
//		for (j = 0; j < str.string_length; j++) {
//			if (string_content[i + j] != str.string_content[j]) break;
//		}
//
//		if (j == str.string_length) return i;
//	}
//
//	return -1;
//}
//int mystring::find(int find_from, const char* str) const {
//	mystring temp(str);
//	return find(find_from, temp);
//}
//
//int mystring::find(int find_from, char c) const {
//	mystring temp(c);
//	return find(find_from, temp);
//}
//
//int mystring::compare(const mystring& str) const {
//
//	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
//		if (string_content[i] > str.string_content[i]) {
//			printf("%d, %d \n", string_content[i], str.string_content[i]);
//			return 1;
//		}
//		else if (string_content[i] < str.string_content[i])
//			return -1;
//	}
//
//	if (string_length == str.string_length) return 0;
//
//	else if (string_length < str.string_length) return 1;
//
//	return -1;
//}
//
//int mystring::compare2(const mystring* str) {
//
//	if (str == nullptr) {
//		return 1;
//	}
//
//	for (int i = 0; i < std::min(string_length, str->string_length); i++) {
//		if (string_content[i] > str->string_content[i]) {
//			printf("%d, %d \n", string_content[i], str->string_content[i]);
//			return 1;
//		}
//		else if (string_content[i] < str->string_content[i])
//			return -1;
//	}
//
//	if (string_length == str->string_length) return 0;
//
//	else if (string_length < str->string_length) return 1;
//
//	return -1;
//}
//
//int main() {
//	mystring str1("very very very long stirng");
//	mystring str2("<some string inserted between>");
//	str1.reserve(30);
//
//	std::cout << "capacity : " << str1.capacity() << std::endl;
//	std::cout << "string length : " << str1.length() << std::endl;
//	str1.println();
//	std::cout << std::endl;
//
//	str1.insert(5, str2);
//	std::cout << "capacity : " << str1.capacity() << std::endl;
//	std::cout << "string length : " << str1.length() << std::endl;
//	str1.println();
//	std::cout << std::endl;
//
//	mystring str3("this is a very very long string");
//	std::cout << "location of first <very> in the stirng : " << str3.find(0, "very") << std::endl;
//	std::cout << "location of second <very> in the string : " << str3.find(str3.find(0, "very") + 1, "very") << std::endl;
//
//	mystring str4("abc");
//	mystring str5("abc");
//
//	std::cout << "compare : " << str4.compare(str5) << std::endl;
//
//	str5.erase(2, 4);
//	std::cout << "capacity : " << str5.capacity() << std::endl;
//	std::cout << "string length : " << str5.length() << std::endl;
//	str5.println();
//
//}
