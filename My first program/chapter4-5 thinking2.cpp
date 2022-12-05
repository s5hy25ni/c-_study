#include <iostream>

class string {
	
	int len;

public:
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

	void find(const string& s) {
		if (len < s.len) { std::cout << "검색 대상보다 짧게 입력" << std::endl; }
		else {
			int find_num = s.len - 1;

		}
	}
};

int main() {
	string a = "a";
	string b = "d";

	std::cout << a.str[0] << std::endl;
	std::cout << b.str[0] << std::endl;

	if (a.str[0] == b.str[0]) { std::cout << "일치" << std::endl; }
	else { std::cout << "불일치" << std::endl; }

}