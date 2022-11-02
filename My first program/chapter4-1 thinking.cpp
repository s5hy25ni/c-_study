#include <iostream>

/*
int input_year, input_month, input_day;

int cheakLeapYear(int year) {
	// �����̸�
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
	return 1;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
	return 1;
	}
	// ����̸�
	else return 0;
}

void cheakInputError() {
	std::cout << std::endl;
	std::cout << "������ �Է��ϼ���." << std::endl << std::endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
}
void getInputYear() {
	std::cout << "���� : ";
	std::cin >> input_year;
}
void getInputMonth() {
	std::cout << "�� : ";
	std::cin >> input_month;
}
void getInputDay() {
	std::cout << "�� : ";
	std::cin >> input_day;
	std::cout << std::endl;
}

void cheakInputDate() {
	while (true) {
		getInputYear();
		if (std::cin.fail()) {
			cheakInputError();
		}
		else if (input_year <= 0) {
			std::cout << "0 �̻��� ������ �Է��ϼ���." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	while (true) {
		getInputMonth();
		if (std::cin.fail()) {
			cheakInputError();
		}
		else if (input_month < 1 || input_month>12) {
			std::cout << "1�� 12 ������ ������ �Է��ϼ���." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	while (true) {
		getInputDay();
		if (std::cin.fail()) {
			cheakInputError();
			continue;
		}
		else {
			switch (input_month) {
			case 2:
				if (cheakLeapYear(input_year)) { // �����̸�
					if (1 > input_day || 29 < input_day) {
						std::cout << "�����Դϴ�. 1�� 29 ������ ������ �Է��ϼ���." << std::endl;
						std::cout << std::endl;
						continue;
					}
				}
				else { // ����̸�
					if (1 > input_day || 28 < input_day) {
						std::cout << "����Դϴ�. 1�� 28 ������ ������ �Է��ϼ���." << std::endl;
						std::cout << std::endl;
						continue;
					}
				}

			case 4:
			case 6:
			case 9:
			case 11:
				if (1 > input_day || 30 < input_day) {
					std::cout << "1�� 30 ������ ������ �Է��ϼ���." << std::endl;
					std::cout << std::endl;
					continue;
				};

			default:
				if (1 > input_day || 31 < input_day) {
					std::cout << "1�� 31 ������ ������ �Է��ϼ���." << std::endl;
					std::cout << std::endl;
					continue;
				};
			}
		}
		return;
	}
}

class Date {
	int year_;
	int month_; // 1���� 12����
	int day_; // 1���� 31����

public:
	void SetDate(int year, int month, int day);

	int GetCurrentMonthTotalDays(int year, int month);

	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	void ShowDate();
};

void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (cheakLeapYear(year)) {
		return 29;
	}
	else return 28;
}

void Date::AddDay(int inc) {
	while (true) {
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
	std::cout << "���� ��¥ : " << year_ << "-" << month_ << "-" << day_ << std::endl << std::endl;
}

int main() {

	Date currentDate;
	int plus_num, select_num;

	std::cout << "=============== ��¥�� �Է����ּ���. ===============" << std::endl << std::endl;
	cheakInputDate();
	currentDate.SetDate(input_year, input_month, input_day);

	while (true) {
		std::cout << std::endl;
		std::cout << "=============== ���ϴ� ����� �����ϼ���. ===============" << std::endl << std::endl;
		currentDate.ShowDate();
		std::cout << "1. ���� ��¥ �ٲٱ�" << std::endl;
		std::cout << "2. ���� ���ϱ�" << std::endl;
		std::cout << "3. �� ���ϱ�" << std::endl;
		std::cout << "4. �� ���ϱ�" << std::endl;
		std::cout << "0. ������" << std::endl << std::endl;
		std::cout << "���� : ";
		std::cin >> select_num;
		std::cout << std::endl;

		if (std::cin.fail()) {
			cheakInputError();
			continue;
		}

		switch (select_num) {
			case 1:
				std::cout << "=============== [ 1. ���� ��¥ �ٲٱ� ] ===============" << std::endl << std::endl;
				cheakInputDate();
				currentDate.SetDate(input_year, input_month, input_day);
				continue;

			case 2:
				std::cout << "=============== [ 2. ���� ���ϱ� ] ===============" << std::endl << std::endl;
				std::cout << "���ϰ� ���� ������ �Է��ϼ���. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "���ϱ⸸ �����մϴ�." << std::endl << std::endl;
					continue;
				}
				currentDate.AddYear(plus_num);
				continue;

			case 3:
				std::cout << "=============== [ 3. �� ���ϱ� ] ===============" << std::endl;
				std::cout << std::endl;
				std::cout << "���ϰ� ���� �������� �Է��ϼ���. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "���ϱ⸸ �����մϴ�." << std::endl << std::endl;
					continue;
				}
				currentDate.AddMonth(plus_num);
				continue;

			case 4:
				std::cout << "=============== [ 4. �� ���ϱ� ] ===============" << std::endl << std::endl;
				std::cout << "���ϰ� ���� �ϼ��� �Է��ϼ���. : ";
				std::cin >> plus_num;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "���ϱ⸸ �����մϴ�." << std::endl << std::endl;
					continue;
				}
				currentDate.AddDay(plus_num);
				continue;

			case 0:
				std::cout << "=============== ���α׷��� �����մϴ�. ===============" << std::endl;
				break;

			default:
				std::cout << "0~4�� �߿� �����ϼ���." << std::endl << std::endl;
				continue;
		}
		break;
	}
}

*/