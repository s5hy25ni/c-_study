//class A {
//private:
//	void private_func() {}
//	int private_num;
//
//	// B�� A�� ģ��!
//	friend class B;
//
//	// func�� A�� ģ��!
//	friend void func();
//};
//
//class B {
//public:
//	void b() {
//		A a;
//
//		// ��� private �Լ��� �ʵ�������� ģ���̱� ������ ���� ������
//		a.private_func();
//		a.private_num = 2;
//	}
//};
//
//void func() {
//	A a;
//
//	// ��� private �Լ��� �ʵ�������� ���� ���������� ģ���̱� ������ ���� ������
//	a.private_func();
//	a.private_num = 2;
//}
//
//int main() {}

#include <cstring>
#include <iostream>

//class Complex {
//private:
//    double real, img;
//
//    double get_number(const char* str, int from, int to) const;
//
//public:
//    Complex(double real, double img) : real(real), img(img) {}
//    Complex(const Complex& c) { real = c.real, img = c.img; }
//    Complex(const char* str);
//
//    Complex& operator=(const Complex& c);
//
//    // ������ ������ �Լ����� ���� :)
//
//    void println() {
//        std::cout << "( " << real << " , " << img << " ) " << std::endl;
//    }
//
//    friend Complex operator+(const Complex& a, const Complex& b);
//    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
//};
//
//Complex operator+(const Complex& a, const Complex& b) {
//    Complex temp(a.real + b.real, a.img + b.img);
//    return temp;
//}
//
//Complex::Complex(const char* str) {
//    // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
//    // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
//    // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
//
//    int begin = 0, end = strlen(str);
//    img = 0.0;
//    real = 0.0;
//
//    // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
//    int pos_i = -1;
//    for (int i = 0; i != end; i++) {
//        if (str[i] == 'i') {
//            pos_i = i;
//            break;
//        }
//    }
//
//    // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
//    if (pos_i == -1) {
//        real = get_number(str, begin, end - 1);
//        return;
//    }
//
//    // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
//    real = get_number(str, begin, pos_i - 1);
//    img = get_number(str, pos_i + 1, end - 1);
//
//    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
//}
//double Complex::get_number(const char* str, int from, int to) const {
//    bool minus = false;
//    if (from > to) return 0;
//
//    if (str[from] == '-') minus = true;
//    if (str[from] == '-' || str[from] == '+') from++;
//
//    double num = 0.0;
//    double decimal = 1.0;
//
//    bool integer_part = true;
//    for (int i = from; i <= to; i++) {
//        if (isdigit(str[i]) && integer_part) {
//            num *= 10.0;
//            num += (str[i] - '0');
//        }
//        else if (str[i] == '.')
//            integer_part = false;
//        else if (isdigit(str[i]) && !integer_part) {
//            decimal /= 10.0;
//            num += ((str[i] - '0') * decimal);
//        }
//        else
//            break;  // �� �̿��� �̻��� ���ڵ��� �� ���
//    }
//
//    if (minus) num *= -1.0;
//
//    return num;
//}
//
//Complex& Complex::operator=(const Complex& c) {
//    real = c.real;
//    img = c.img;
//    return *this;
//}
//
//std::ostream& operator<<(std::ostream& os, const Complex& c) {
//    os << "( " << c.real << " , " << c.img << " )";
//    return os;
//}
//
//int main() {
//    Complex a(0, 0);
//    a = "-1.1 + i3.923" + a;
//    std::cout << "a�� ���� : " << a << " �̴�. " << std::endl;
//}

//class MyString {
//    char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
//    int string_length;     // ���ڿ� ����
//
//    int memory_capacity;  // ���� �Ҵ�� �뷮
//
//public:
//    // ���� �ϳ��� ����
//    MyString(char c);
//
//    // ���ڿ��� ���� ����
//    MyString(const char* str);
//
//    // ���� ������
//    MyString(const MyString& str);
//
//    ~MyString();
//
//    int length();
//
//    void print() const;
//    void println() const;
//
//    char& operator[](const int index);
//};
//
//MyString::MyString(char c) {
//    string_content = new char[1];
//    string_content[0] = c;
//    memory_capacity = 1;
//    string_length = 1;
//}
//MyString::MyString(const char* str) {
//    string_length = strlen(str);
//    memory_capacity = string_length;
//    string_content = new char[string_length];
//
//    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
//}
//MyString::MyString(const MyString& str) {
//    string_length = str.string_length;
//    string_content = new char[string_length];
//
//    for (int i = 0; i != string_length; i++)
//        string_content[i] = str.string_content[i];
//}
//MyString::~MyString() { delete[] string_content; }
//int MyString::length() { return string_length; }
//void MyString::print() const {
//    for (int i = 0; i != string_length; i++) {
//        std::cout << string_content[i];
//    }
//}
//void MyString::println() const {
//    for (int i = 0; i != string_length; i++) {
//        std::cout << string_content[i];
//    }
//    std::cout << std::endl;
//}
//
//char& MyString::operator[](const int index) { return string_content[index]; }
//
//int main() {
//    MyString str("abcdef");
//    str[3] = 'c';
//
//    str.println();
//}

//class Int {
//	int data;
//	// some other data
//
//public:
//	Int(int data) : data(data) {}
//	Int(const Int& i) : data(i.data) {}
//
//	operator int() { return data; }
//};
//
//int main() {
//	Int x = 3;
//	int a = x + 4;
//
//	x = a * 2 + x + 4;
//	std::cout << x << std::endl;
//}

//class Test {
//	int x;
//
//public:
//	Test(int x) : x(x) {}
//	Test(const Test& t) : x(t.x) {}
//
//	Test& operator++() {
//		x++;
//		std::cout << "���� ���� ������" << std::endl;
//		return *this;
//	}
//
//	// ������ ���̸� �α� ���� ���ڷ� int�� ������ �����δ� �ƹ��͵� ���޵��� ����
//	Test operator++(int) {
//		Test temp(*this);
//		x++;
//		std::cout << "���� ���� ������" << std::endl;
//		return temp;
//	}
//
//	int get_x() const {
//		return x;
//	}
//};
//
//void func(const Test& t) {
//	std::cout << "x: " << t.get_x() << std::endl;
//}
//
//int main() {
//	Test t(3);
//
//	func(++t); // 4
//	func(t++); // 4
//	std::cout << "x : " << t.get_x() << std::endl;
//}