#include <iostream>
#include <string>

//class Base {
//public:
//	Base() { std::cout << "��� Ŭ����" << std:: endl; }
//	virtual void what() { std::cout << "��� Ŭ������ what()" << std:: endl; }
//};
//
//class Derived : public Base {
//public:
//	Derived() : Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }
//	void what() { std::cout << "�Ļ� Ŭ������ what()" << std::endl; }
//};
//
//int main() {
//	Base p;
//	Derived c;
//
//	Base* p_c = &c;
//	Base* p_p = &p;
//
//	std::cout << "== ���� ��ü�� Base ==" << std::endl;
//	p_p->what();
//
//	std::cout << "== ���� ��ü�� Derived ==" << std::endl;
//	p_c->what();
//
//	return 0;
//}

//class Base {
//	std::string s;
//
//public:
//	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }
//
//	void what() { std::cout << s << std::endl; }
//};
//class Derived : public Base {
//	std::string s;
//
//public:
//	Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }
//
//	void what() { std::cout << s << std::endl; }
//};
//int main() {
//	Base p;
//	Derived c;
//
//	std::cout << "=== ������ ���� ===" << std::endl;
//	Base* p_c = &c;
//	p_c->what();
//
//	return 0;
//}

class Base {
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }
	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std:: endl; }
	void what() override { std::cout << s << std::endl; }
};