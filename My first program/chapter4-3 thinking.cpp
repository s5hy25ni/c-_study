//#include <iostream>
//
//class string {
//	
//	int len;
//
//public:
//	char* str;
//
//	string(char c, int n) { // 문자 c 가 n 개 있는 문자열로 정의
//		len = n;
//		str = new char[len+1];
//		for (int i = 0; i < len+1; i++) {
//			if (i < len) {
//				str[i] = c;
//			}
//			else str[i] = '\0';
//		}
//	};  
//	string(const char* s) { // hello
//		for (len = 0; s[len] != '\0'; len++) {}
//
//		str = new char[len+1];
//		for (int i = 0; i < len+1; i++) {
//			str[i] = s[i];
//		}
//	};
//	string(const string& s) {
//		len = s.len;
//		str = new char[len+1];
//		for (int i = 0; i < len+1; i++) {
//			str[i] = s.str[i];
//		}
//	};
//	~string() {
//		delete[] str;
//	}
//
//	void add_string(const string& s) { // str 뒤에 s 를 붙인다.
//		string temp(str); //temp.str = aaa, temp.len = 3
//		len += s.len; // len = 3+5 = 8
//		str = new char[len+1]; // str = new char[9]
//		for (int i = 0; i < temp.len+1; i++) { // i<4 -> str[0] = a, str[1] = a, str[2] = a. str[3] = \0
//			str[i] = temp.str[i];
//		}
//		for (int i = temp.len, j = 0; i < len+1; i++, j++) { // i = 3; i<8 -> str[3] = h, str[4] = e, str[5] = l, str[6] = l, str[7] = o str[8] = \0
//			str[i] = s.str[j];
//		}
//	};   
//
//	void copy_string(const string& s) { // str 에 s 를 복사한다.
//		if (len < s.len) {
//			len = s.len;
//			str = new char[s.len + 1];
//			for (int i = 0; i < len + 1; i++) {
//				str[i] = s.str[i];
//			}
//		}
//		else {
//			len = s.len;
//			for (int i = 0; i < len + 1; i++) {
//				str[i] = s.str[i];
//			}
//		}
//	};  
//	int strlen() {
//		return len;
//	};                       // 문자열 길이 리턴
//};
//
//int main() {
//	string a('a', 3);
//	string b = "hello";
//	string c = a;
//
//	std::cout << "a.str : " << a.str << std::endl;
//	std::cout << "a.len : " << a.strlen() << std::endl;
//	std::cout << "b.str : " << b.str << std::endl;
//	std::cout << "b.len : " << b.strlen() << std::endl;
//	std::cout << "c.str : " << c.str << std::endl;
//	std::cout << "c.len : " << c.strlen() << std::endl;
//
//	a.add_string(b); // a=aaahello, b=hello, c=aaa
//	std::cout << "a.str += b.str : " << a.str << std::endl;
//	std::cout << "a.len += b.str : " << a.strlen() << std::endl;
//	std::cout << "b.str : " << b.str << std::endl;
//	std::cout << "b.len : " << b.strlen() << std::endl;
//
//	// 복사 글자가 더 긴 경우
//	b.copy_string(a); // a=aaahello, b=aaahello, c=aaa
//	std::cout << "b.str = a.str : " << b.str << std::endl;
//	std::cout << "b.len = a.str : " << b.strlen() << std::endl;
//	std::cout << "a.str : " << a.str << std::endl;
//	std::cout << "a.len : " << a.strlen() << std::endl;
//
//	// 복사 글자가 더 짧은 경우
//	b.copy_string(c); // a=aaahello, b=aaa, c=aaa
//	std::cout << "b.str = c.str : " << b.str << std::endl;
//	std::cout << "b.len = c.str : " << b.strlen() << std::endl;
//	std::cout << "c.str : " << c.str << std::endl;
//	std::cout << "c.len : " << c.strlen() << std::endl;
//}