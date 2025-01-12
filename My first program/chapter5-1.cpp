//#include <string.h>
//#include <iostream>
////
////class MyString {
////	char* string_content;
////	int string_length;
////
////	int memory_capacity;
////
////public :
////	MyString(char c);
////	MyString(const char* str);
////	MyString(const MyString& str);
////
////	~MyString();
////
////	int length() const;
////	int capacity() const;
////	void reserve(int size);
////
////	void print() const;
////	void println() const;
////
////	char at(int i) const;
////
////	int compare(MyString& str);
////	bool operator==(MyString& str);
////};
////
////MyString::MyString(char c) {
////	string_content = new char[1];
////	string_content[0] = c;
////	memory_capacity = 1;
////	string_length = 1;
////}
////
////MyString::MyString(const char* str) {
////	string_length = strlen(str);
////	memory_capacity = string_length;
////	string_content = new char[string_length];
////
////	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
////}
////
////MyString::MyString(const MyString& str) {
////	string_length = str.string_length;
////	string_content = new char[string_length];
////
////	for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
////}
////
////MyString::~MyString() { delete[] string_content; }
////
////int MyString::length() const { return string_length; }
////
////void MyString::print() const {
////	for (int i = 0; i != string_length; i++) std::cout << string_content[i];
////}
////
////void MyString::println() const {
////	for (int i = 0; i != string_length; i++) std::cout << string_content[i];
////	std::cout << std::endl;
////}
////
////int MyString::capacity() const { return memory_capacity; }
////
////void MyString::reserve(int size) {
////	if (size > memory_capacity) {
////		char* prev_string_content = string_content;
////
////		string_content = new char[size];
////		memory_capacity = size;
////
////		for (int i = 0; i != string_length; i++) string_content[i] = prev_string_content[i];
////
////		delete[] prev_string_content;
////	}
////}
////
////char MyString::at(int i) const {
////	if (i >= string_length || i < 0) return 0;
////	else return string_content[i];
////}
////
////int MyString::compare(MyString& str) {
////	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
////		if (string_content[i] > str.string_content[i]) return 1;
////		else if (string_content[i] < str.string_content[i]) return -1;
////	}
////	
////	if (string_length == str.string_length) return 0;
////
////	else if (string_length < str.string_length) return 1;
////
////	return -1;
////}
////
////bool MyString::operator==(MyString & str) {
////	return !compare(str); // str 과 같으면 compare 에서 0을 리턴한다.
////}
////
////int main() {
////	MyString str1("a word");
////	MyString str2("sentence");
////	MyString str3("sentence");
////
////	if (str1 == str2) std::cout << "str1 와 str2 는 같다." << std::endl;
////	else std::cout << "str1 와 str2 는 다르다." << std::endl;
////
////	if (str2 == str3) std::cout << "str2 와 str3 는 같다" << std::endl;
////	else std::cout << "str2 와 str3 는 다르다." << std::endl;
////}
//
//class Complex {
//private:
//	double real, img;
//	double get_number(const char* str, int from, int to) const;
//
//public:
//	Complex(double real, double img) : real(real), img(img) {}
//	Complex(const Complex& c) { real = c.real, img = c.img; }
//	Complex(const char* str);
//	
//	Complex operator+(const Complex& c) const;
//	Complex operator-(const Complex& c) const;
//	Complex operator*(const Complex& c) const;
//	Complex operator/(const Complex& c) const;
//
//	Complex operator+(const char* str) const;
//	Complex operator-(const char* str) const;
//	Complex operator*(const char* str) const;
//	Complex operator/(const char* str) const;
//
//	Complex& operator+=(const Complex& c);
//	Complex& operator-=(const Complex& c);
//	Complex& operator*=(const Complex& c);
//	Complex& operator/=(const Complex& c);
//
//	Complex& operator=(const Complex& c);
//
//	void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
//};
//
//Complex::Complex(const char* str) {
//	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾음
//	// 문자열의 꼴은 (부호) (실수부) (부호) i (허수부)
//	// 부호는 생략 가능 => 생략시 +
//
//	int begin = 0, end = strlen(str);
//	img = 0.0;
//	real = 0.0;
//
//	// 먼저 가장 기준이 되는 'i'의 위치를 찾음
//	int pos_i = -1;
//	for (int i = 0; i != end; i++) {
//		if (str[i] == 'i') {
//			pos_i = i;
//			break;
//		}
//	}
//
//	// 만약 'i'가 없다면 이 수는 실수 뿐
//	if (pos_i == -1) {
//		real = get_number(str, begin, end - 1);
//		return;
//	}
//
//	// 만일 'i'가 있다면, 실수부와 허수부를 나누어서 처리
//	real = get_number(str, begin, pos_i - 1);
//	img = get_number(str, pos_i + 1, end - 1);
//
//	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
//}
//
//double Complex::get_number(const char* str, int from, int to) const {
//	bool minus = false;
//	if (from > to) return 0;
//
//	if (str[from] == '-') minus = true;
//	if (str[from] == '-' || str[from] == '+') from++;
//
//	double num = 0.0;
//	double decimal = 1.0;
//
//	bool integer_part = true;
//	for (int i = from; i <= to; i++) {
//		if (isdigit(str[i]) && integer_part) {
//			num *= 10.0;
//			num += (str[i] - '0');
//		}
//		else if (str[i] == '.') {
//			integer_part = false;
//		}
//		else if (isdigit(str[i]) && !integer_part) {
//			decimal /= 10.0;
//			num += ((str[i] - '0') * decimal);
//		}
//		else break; // 그 외 이상한 문자들이 올 경우
//	}
//
//	if (minus) num *= -1.0;
//
//	return num;
//};
//
//Complex Complex::operator+(const Complex& c) const {
//	Complex temp(real + c.real, img + c.img);
//	return temp;
//}
//
//Complex Complex::operator-(const Complex& c) const {
//	Complex temp(real - c.real, img - c.img);
//	return temp;
//}
//
//Complex Complex::operator*(const Complex& c) const {
//	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//	return temp;
//}
//
//Complex Complex::operator/(const Complex& c) const {
//	Complex temp(
//		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
//	);
//	return temp;
//}
//
//Complex Complex::operator+(const char* str) const {
//	Complex temp(str);
//	return (*this) + temp;
//}
//
//Complex Complex::operator-(const char* str) const {
//	Complex temp(str);
//	return (*this) - temp;
//}
//
//Complex Complex::operator*(const char* str) const {
//	Complex temp(str);
//	return (*this) * temp;
//}
//
//Complex Complex::operator/(const char* str) const {
//	Complex temp(str);
//	return (*this) / temp;
//}
//
//Complex& Complex::operator+=(const Complex& c) {
//	(*this) = (*this) + c;
//	return *this;
//}
//
//Complex& Complex::operator-=(const Complex& c) {
//	(*this) = (*this) - c;
//	return *this;
//}
//
//Complex& Complex::operator*=(const Complex& c) {
//	(*this) = (*this) * c;
//	return *this;
//}
//
//Complex& Complex::operator/=(const Complex& c) {
//	(*this) = (*this) / c;
//	return *this;
//}
//
//Complex& Complex::operator=(const Complex& c) {
//	real = c.real;
//	img = c.img;
//
//	return *this;
//}
//
//int main() {
//	Complex a(0, 0);
//	a = a + "-1.1 + i3.923";
//	a.println();
//	a = a - "1.2 - i1.823";
//	a.println();
//	a = a * "2.3 + i22";
//	a.println();
//	a = a / "-12 + i55";
//	a.println();
//};