#include <iostream>

class string {
	

public:
	char* str;
	int len;

	string(char c, int n) { // 문자 c 가 n 개 있는 문자열로 정의
		len = n;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = c;
		}
	};  
	string(const char* s) {
		while (true) {
			if (*s == '\0') break;
			else len++; s++;
		}
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = s[i];
		}
	};
	string(const string& s) {
		len = s.len;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = s.str[i];
		}
	};
	~string() {
		delete[] str;
	}

	void add_string(const string& s) { // str 뒤에 s 를 붙인다.
		string temp(str);
		len += s.len;
		str = new char[len];
		for (int i = 0; i < temp.len; i++) {
			str[i] = temp.str[i];
		}
		for (int i = temp.len; i < len; i++) {
			str[i] = s.str[i];
		}
	};   
	void copy_string(const string& s);  // str 에 s 를 복사한다.
	int strlen();                       // 문자열 길이 리턴
};

int main() {
	string a('a', 3);
	string b = "hello";
	string c = a;

	a.add_string(b);
	std::cout << a.str << std::endl;
	std::cout << a.len << std::endl;
}