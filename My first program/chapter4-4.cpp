#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning ( disable : 4996 )

/* ���� 
class Marine {

	static int total_marine_num;
	const static int i = 0;

	int hp;									// ���� ü��
	int coord_x, coord_y;					// ���� ��ġ
	bool is_dead;

	const int default_damage;				// �⺻ ���ݷ�

	public:
		Marine();							// �⺻ ������
		Marine(int x, int y);				// x,y ��ǥ�� ���� ����
		Marine(int x, int y, int default_damage);

		int attack() const;						// �������� �����Ѵ�.
		Marine& be_attacked(int damage_earn);	// ���� ������
		void move(int x, int y);			// ���ο� ��ġ

		void show_status();					// ���¸� �����ش�.

		static void show_total_marine();
		~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}

Marine::Marine() 
	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y) 
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) 
	: coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() const { return default_damage; }

Marine& Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}

void Marine::show_status() {
	std::cout << " *** Marine ***" << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}
int main() {

	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}

*/


/* ���۷����� �����ϴ� �Լ� 
class A {
	int x;

public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	// error
	// int& e = a.get_X();
	// e = 2;
	// a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
}
*/

/* thinking 
class A {
	int x;

public:
	A(int c) : x(c) {}
	A(const A& a) {
		x = a.x;
		std::cout << "���� ����" << std::endl;
	}
};

class B {
	A a;

public:
	B(int c) : a(c) {}
	B(const B& b) : a(b.a) {}
	A get_A() {
		A temp(a);
		return temp;
	}
};

int main() {
	B b(10);

	std::cout << "---------" << std::endl;
	A a1 = b.get_A();
}
*/