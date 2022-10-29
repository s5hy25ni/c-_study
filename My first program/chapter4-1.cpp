#include <iostream>

/* class 
class Animal {
private:
	int food;
	int weight;

	void increase_weight(int inc) {
		weight += (inc / 3);
	}

public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		increase_weight(inc);
	}
	void view_stat() {
		std::cout << "�� ������ food : " << food << std::endl;
		std::cout << "�� ������ weight : " << weight << std::endl;
	}
};

int main() {
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}
*/

/* think */
class Date {
	int year_;
	int month_; // 1���� 12����
	int day_; // 1���� 31����
	
	int cal_day = 0;

	public:
		void SetDate(int year, int month, int day) {
			year_ = year;
			month_ = month;
			day_ = day;
		};
		void AddDay(int inc) {
		};
		void AddMonth(int inc);
		void AddYear(int inc) {
			year_ += inc;
		};

		void ShowDate() {
			std::cout << "���� ��¥�� " << year_ << "�� " << month_ << "�� " << day_ << "�� �Դϴ�." << std::endl;
		}
}; 

int select_num, input_year, input_month, input_day;

void input_not_int() {
	std::cout << "������ �Է��ϼ���." << std::endl;;
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

void get_input_year() {
	std::cout << "���� : ";
	std::cin >> input_year;
}
void get_input_month() {
	std::cout << "�� : ";
	std::cin >> input_month;
}
void get_input_day() {
	std::cout << "�� : ";
	std::cin >> input_day;
}

int main() {

	Date inputDate;

	for (;;) {
		std::cout << "���ϴ� ����� �����ϼ���." << std::endl;
		std::cout << "1. ��¥ �Է��ϱ�" << std::endl;
		std::cout << "2. ���� ���ϱ�" << std::endl;
		std::cout << "2. �� ���ϱ�" << std::endl;
		std::cout << "3. �� ���ϱ�" << std::endl;
		std::cout << "0. ������" << std::endl;
		std::cin >> select_num;

		switch (input_year) {
			case NULL :
				std::cout << "��¥ ������ �������� �ʽ��ϴ�. [1. ��¥ �Է��ϱ�]�� �̵��մϴ�." << std::endl;
				goto default;

		}
	}

	for (;;) {
		get_input_year();
		if (std::cin.fail()) {
			input_not_int();
			continue;
		}
		else if (input_year <= 0) {
			std::cout << "0 �̻��� ������ �Է��ϼ���." << std::endl;
			continue;
		}
		else break;
	}

	for (;;) {
		get_input_month();
		if (std::cin.fail()) {
			input_not_int();
			continue;
		}
		else if (input_month < 1 || input_month>12) {
			std::cout << "1�� 12 ������ ������ �Է��ϼ���." << std::endl;
			continue;
		}
		else break;
	}

	for (;;) {
		get_input_day();
		if (std::cin.fail()) {
			input_not_int();
			continue;
		}
		else {
			switch (input_month) {
				case (4, 6, 9, 11) :
					if (1 <= input_day && input_day <= 30) {
						inputDate.SetDate(input_year, input_month, input_day);
						inputDate.ShowDate();
					}
					else {
						std::cout << "1�� 30 ������ ������ �Է��ϼ���." << std::endl;
						continue;
					}

				case 2 :
					if (1 <= input_day && input_day <= 28) {
						inputDate.SetDate(input_year, input_month, input_day);
						inputDate.ShowDate();
					}
					else {
						std::cout << "1�� 28 ������ ������ �Է��ϼ���." << std::endl;
						continue;
					}
				default :
					if (1 <= input_day && input_day <= 31) {
						inputDate.SetDate(input_year, input_month, input_day);
						inputDate.ShowDate();
					}
					else {
						std::cout << "1�� 31 ������ ������ �Է��ϼ���." << std::endl;
						continue;
					}
			}
		break;
		}
	}
}