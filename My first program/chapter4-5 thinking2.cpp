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
	string(char c, int n) { // ���� c �� n �� �ִ� ���ڿ��� ����
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
		if (len < s.len) { std::cout << "�˻� ��󺸴� ª�� �Է�" << std::endl; }
		else {
			int find_num = s.len - 1;
			int not_same = 0;
			for (int i = find_num; i > find_num-s.len; i--) {
				if (str[i] == s.str[i]) {
					std::cout << i << "��° ���� ��ġ" << std::endl;
				}
				else {
					std::cout << i << "��° ���� ����ġ" << std::endl;
				}
			}

		}
	}
};

int main() {
	string a = "hello, sohyeon!";
	string b = "soh"; 

	a.find(b);
}