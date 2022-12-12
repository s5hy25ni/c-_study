#include <iostream>

class string {

public:
	int len;
	char* str;

	string(char c) {
		len = 1;
		str = new char[2];
		str[0] = c;
		str[1] = '\0';
	}
	string(char c, int n) { // 문자 c 가 n 개 있는 문자열로 정의
		len = n;
		str = new char[len+1];
		for (int i = 0; i < len+1; i++) {
			if (i < len) {
				str[i] = c;
			}
			else str[i] = '\0';
		}
	};  
	string(const char* s) { // hello
		for (len = 0; s[len] != '\0'; len++) {}

		str = new char[len+1];
		for (int i = 0; i < len+1; i++) {
			str[i] = s[i];
		}
	};
	string(const string& s) {
		len = s.len;
		str = new char[len+1];
		for (int i = 0; i < len+1; i++) {
			str[i] = s.str[i];
		}
	};
	~string() {
		delete[] str;
	}

	string operator+(const string& s) const {
		int temp_len = len + s.len;
		char* temp_str = new char[temp_len+1];
		int i;
		for (i = 0; i < len; i++) {
			temp_str[i] = str[i];
		}

		for (int j = 0; j < s.len+1; j++) {
			if (j < s.len) {
				temp_str[i + j] = s.str[j];
			}
			else {
				temp_str[i + j] = '\0';
			}
		}

		string temp(temp_str);

		return temp;
	}
	
};

int main() {
	string a = "hello, sohyeon!";
	string b = "o"; 

	a = a + b;

	std::cout << a.len << std::endl;
	std::cout << a.str << std::endl;

}