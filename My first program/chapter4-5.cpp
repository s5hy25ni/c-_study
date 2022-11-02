#include <iostream>
#include <string.h>

class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮

public:
	// ���� �ϳ��� ����
	MyString(char c);

	// ���ڿ��κ��� ����
	MyString(const char* str);

	// ���� ������
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	
	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);

	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;
	int compare2(const MyString* str);

};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		// �ٽ� �Ҵ�
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > string_length) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}
}

char MyString::at(int i) const {
	if (i >= string_length || i < 0) {
		return NULL;
	}
	else return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
	// ������ ����� �Է¿� ���ؼ��� ������ �������� ����
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		// ���Ӱ� ���� �Ҵ�
		if (memory_capacity * 2 > string_length + str.string_length) memory_capacity *= 2;
		else memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// insert �Ǵ� �κ� �������� ���� ����
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}

		// ���Ӱ� insert �Ǵ� ���ڿ� ����
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}

		// �� ���ڿ��� ������ �޺κ� ����
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// ���� �ʰ����� �ʴ´ٸ� ���� �����Ҵ� ���ص� ��
	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];
	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[i + loc] = str.string_content[i];

		string_length = string_length + str.string_length;
		return *this;
	}
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
	// loc�� �� ���� ������ num ���ڸ� ����
	if (num < 0 || loc < 0 || loc > string_length) return *this;

	if (num > string_length) num = string_length;

	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}

	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1;
}
int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) {
			printf("%d, %d \n", string_content[i], str.string_content[i]);
			return 1;
		}
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	if (string_length == str.string_length) return 0;

	else if (string_length < str.string_length) return 1;

	return -1;
}

int MyString::compare2(const MyString* str) {

	if (str == nullptr) {
		return 1;
	}

	for (int i = 0; i < std::min(string_length, str->string_length); i++) {
		if (string_content[i] > str->string_content[i]) {
			printf("%d, %d \n", string_content[i], str->string_content[i]);
			return 1;
		}
		else if (string_content[i] < str->string_content[i])
			return -1;
	}

	if (string_length == str->string_length) return 0;

	else if (string_length < str->string_length) return 1;

	return -1;
}

int main() {
	MyString str1("very very very long stirng");
	MyString str2("<some string inserted between>");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	std::cout << std::endl;

	str1.insert(5, str2);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	std::cout << std::endl;

	MyString str3("this is a very very long string");
	std::cout << "Location of first <very> in the stirng : " << str3.find(0, "very") << std::endl;
	std::cout << "Location of second <very> in the string : " << str3.find(str3.find(0, "very") + 1, "very") << std::endl;

	MyString str4("abc");
	MyString str5("ABC");

	std::cout << "compare : " << str4.compare(str5) << std::endl;

	str5.erase(2, 4);
	std::cout << "Capacity : " << str5.capacity() << std::endl;
	std::cout << "String length : " << str5.length() << std::endl;
	str5.println();

}
