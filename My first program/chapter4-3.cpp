#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning ( disable : 4996 )

/* ���� 
class Marine {
	int hp;									// ���� ü��
	int coord_x, coord_y;					// ���� ��ġ
	int damage;								// ���ݷ�
	bool is_dead;
	char* name;								// ���� �̸�

	public:
		Marine();							// �⺻ ������
		Marine(int x, int y);				// x,y ��ǥ�� ���� ����
		Marine(int x, int y, const char* marine_name); // �̸����� ����
		~Marine();

		int attack();						// �������� �����Ѵ�.
		void be_attacked(int damage_earn);	// ���� ������
		void move(int x, int y);			// ���ο� ��ġ

		void show_status();					// ���¸� �����ش�.
};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << " *** Marine : " << name << " ***" << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

Marine::~Marine() {
	std::cout << name << "�� �Ҹ��� ȣ��!" << std::endl;
	if (name != NULL) {
		delete[] name;
	}
}
*/


/* �ܼ��� ��Ȳ
int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "���� 1�� ���� 2�� ����!" << std::endl << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}
*/

/* ���ʸ����� ����
int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(3, 5, "Marine 1");

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "���� 1�� ���� 2�� ����!" << std::endl << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
};
*/


/*
class Test {
	char c;

	public :
		Test(char _c) {
			c = _c;
			std::cout << "������ ȣ��" << c << std::endl;
		}
		~Test() { std::cout << "�Ҹ��� ȣ��" << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main() {
	Test a('a');
	simple_function();
}
*/

/* ���� ������ 
class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon_Cannon& pc);
	~Photon_Cannon();

	void show_status();
	;
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "������ ȣ��!" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	std::cout << "������ ȣ��!" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "���� ������ ȣ��! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	// name�� ���� �Ҵ�
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}


Photon_Cannon::~Photon_Cannon() {
	// 0�� �ƴ� ���� if ������ true
	// if(name != 0)�� if(name)�� ������ �ǹ�
	if (name) delete[] name;
}


void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon :: " << name << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;

	pc1.show_status();
	pc2.show_status();

}

*/