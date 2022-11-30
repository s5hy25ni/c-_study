#include <iostream>

class string {
	

public:
	char* str;
	int len;

	string(char c, int n) { // ���� c �� n �� �ִ� ���ڿ��� ����
		len = n;
		str = new char[len];
		for (int i = 0; i <= len; i++) {
			if (i < len) {
				str[i] = c;
			}
			else str[i] = '\0';
		}
	};  
	string(const char* s) { // hello
		len = 0;
		while (true) {
			len++;
			if (s[len] == '\0') {
				break;
			}
		}
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = s[i-len];
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

	void add_string(const string& s) { // str �ڿ� s �� ���δ�.
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
	void copy_string(const string& s);  // str �� s �� �����Ѵ�.
	int strlen();                       // ���ڿ� ���� ����
};

int main() {
	string a('a', 3);
	string b = "hello";
	string c = a;

	//a.add_string(b);
	std::cout << a.str << std::endl;
	std::cout << a.len << std::endl;
	std::cout << b.str << std::endl;
	std::cout << b.len << std::endl;
}