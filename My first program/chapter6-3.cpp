#include <iostream>

//class Parent {
//public:
//	Parent() { std::cout << "Parent ������ ȣ��" << std::endl; }
//	virtual ~Parent() { std::cout << "Parent �Ҹ��� ȣ��" << std::endl; }
//};
//
//class Child : public Parent {
//public:
//	Child() :Parent() { std::cout << "Child ������ ȣ��" << std::endl; }
//	~Child() { std::cout << "Child �Ҹ��� ȣ��" << std::endl; }
//};
//
//int main() {
//	std::cout << "=== ����� Child ������� �� ===" << std::endl;
//	{ Child c; }
//	std::cout << "=== Parent �����ͷ� Child �������� �� ===" << std::endl;
//	{
//		Parent* p = new Child();
//		delete p;
//	}
//}

//class A {
//public:
//	virtual void show() { std::cout << "Parent!" << std::endl; }
//};
//
//class B : public A {
//public:
//	void show() override { std::cout << "Child!" << std::endl; }
//};
//
//void test(A& a) { a.show(); }
//
//int main() {
//	A a;
//	B b;
//	test(a);
//	test(b);
//
//	return 0;
//}

class Parent {
public:
	virtual void func1();
	virtual void func2();
};

class Child : public Parent {
public:
	virtual void func1();
	void func3();
};