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

	void badCharSearch(const string& txt, const string& pat) {
		
	}
	void find(const string& s) {
		if (len < s.len) { std::cout << "pattern is too longer" << std::endl; }
		else {
			std::cout << "START : find pattern(" << s.str << ") in text(" << str << ")" << std::endl << std::endl;

			// badChar ��ó��
			int badChar[256];
			for (int i = 0; i < 256; i++) { // ��� ���� -1�� �ʱ�ȭ
				badChar[i] = -1;
			}
			for (int i = 0; i < s.len; i++) { // s.str�� �ִ� ������ �ε��� ����(�ߺ��� ���� ������ �ε���)
				badChar[(int)s.str[i]] = i;
			}

			int start = 0; // �˻� ���� �ε���
			int pat_num = 0;

			while (start <= (len - s.len)) { // �˻� ���� �ε����� (s.len - len) ���� Ŭ �� ����
				int j = s.len - 1; // ���ڿ� ���������� �˻��ϱ� ����
				while (j >= 0 && s.str[j] == str[start + j]) { // 
					j--;
				}
				if (j < 0) {
					pat_num++;
					std::cout << pat_num << " pattern : str[" << start << "] ~ [" << start+s.len-1 << "]" << std::endl;
					start += (start + s.len < len) ? s.len - badChar[str[start + s.len]] : 1;
				}
				else {
					start += std::max(1, j - badChar[str[start + j]]);
				}
			}

			if (pat_num == 0) std::cout << "END : pattern is not in text" << std::endl;
			else std::cout << std::endl << "END : " << pat_num << " pattern is in text" << std::endl;

		}
	}
};

int main() {
	string a = "hello, sohyeon!";
	string b = "o"; 

	a.find(b);
}