#include <iostream>

int input_year, input_month, input_day, select_num;

void input_not_int() {
	std::cout << std::endl;
	std::cout << "������ �Է��ϼ���." << std::endl << std::endl;
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
	std::cout << std::endl;
}

int cheak_year(int year) {
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
		return 1;
	}
	else if (year % 4 == 0 && year % 100 == 0) {
		return 0;
	}
	else if (year % 4 == 0) {
		return 1;
	}
	else return 0;
}

void get_input_date() {
	while (true) {
		get_input_year();
		if (std::cin.fail()) {
			input_not_int();
		}
		else if (input_year <= 0) {
			std::cout << "0 �̻��� ������ �Է��ϼ���." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	while (true) {
		get_input_month();
		if (std::cin.fail()) {
			input_not_int();
		}
		else if (input_month < 1 || input_month>12) {
			std::cout << "1�� 12 ������ ������ �Է��ϼ���." << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	while (true) {
		int input_end = 1;
		get_input_day();
		if (std::cin.fail()) {
			input_not_int();
		}
		else {
			switch (input_month) {
			case 2:
				if (cheak_year(input_year)) { // �����̸�
					if (1 > input_day || 29 < input_day) {
						std::cout << "�����Դϴ�. 1�� 29 ������ ������ �Է��ϼ���." << std::endl;
						std::cout << std::endl;
						input_end = 0;
					}
				}
				else { // ����̸�
					if (1 > input_day || 28 < input_day) {
						std::cout << "����Դϴ�. 1�� 28 ������ ������ �Է��ϼ���." << std::endl;
						std::cout << std::endl;
						input_end = 0;
					}
				}
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (1 > input_day || 30 < input_day) {
					std::cout << "1�� 30 ������ ������ �Է��ϼ���." << std::endl;
					std::cout << std::endl;
					input_end = 0;
				};
				break;

			default:
				if (1 > input_day || 31 < input_day) {
					std::cout << "1�� 31 ������ ������ �Է��ϼ���." << std::endl;
					std::cout << std::endl;
					input_end = 0;
				};
				break;
			}
		}
		if (input_end) break;
	}
}

class Date {
	int year_;
	int month_; // 1���� 12����
	int day_; // 1���� 31����

	int cal_month;
	int cal_day;
	int cal_end;

	void cheak_month(int inc) {
		while (true) {
			cal_end = 1;
			switch (month_) {
			case 2:
				if (cheak_year(year_)) {
					if (cal_day <= 29) {
						day_ = cal_day;
					}
					else {
						cal_day -= 29;
						AddMonth(1);
						cal_end = 0;
					}
				}
				else {
					if (cal_day <= 28) {
						day_ = cal_day;
					}
					else {
						cal_day -= 28;
						AddMonth(1);
						cal_end = 0;
					}
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (cal_day <= 30) {
					day_ = cal_day;
				}
				else {
					cal_day -= 30;
					AddMonth(1);
					cal_end = 0;
				}
				break;
			default:
				if (cal_day <= 31) {
					day_ = cal_day;
				}
				else {
					cal_day -= 31;
					AddMonth(1);
					cal_end = 0;
				}
				break;
			}
			if (cal_end) break;
		}
	}

public:
	void SetDate(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	};
	void AddDay(int inc) {
		while (true) {
			if (cheak_year(year_)) {
				if (inc > 366) {
					year_ += 1;
					inc -= 366;
					continue;
				}
				else break;
			}
			else {
				if (inc > 365) {
					year_ += 1;
					inc -= 365;
					continue;
				}
				else break;
			}
		}
		
		cal_day = day_ + inc;
		while (true) {
			if (cheak_year(year_)) {
				if (cal_day > 366) {
					AddYear(1);
					cal_day -= 366;
					continue;
				}
				else {
					cheak_month(cal_day);
					break;
				}
			}
			else {
				if (cal_day > 365) {
					AddYear(1);
					cal_day -= 365;
					continue;
				}
				else {
					cheak_month(cal_day);
					break;
				}
			}
		}
	};
	void AddMonth(int inc) {
		AddYear(inc / 12);
		inc %= 12;
		cal_month = month_ + inc;
		if (cal_month <= 12) month_ = cal_month;
		else {
			AddYear(1);
			month_ = cal_month - 12;
		}
	};
	void AddYear(int inc) {
		year_ += inc;
	};

	void ShowDate() {
		std::cout << "���� ��¥�� " << year_ << "�� " << month_ << "�� " << day_ << "�� �Դϴ�." << std::endl << std::endl;
	}
};

int main() {

	Date currentDate;
	int plus_num;

	std::cout << "=============== ��¥�� �Է����ּ���. ===============" << std::endl << std::endl;
	get_input_date();
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
			input_not_int();
			continue;
		}

		switch (select_num) {
			case 1:
				std::cout << "=============== [ 1. ���� ��¥ �ٲٱ� ] ===============" << std::endl << std::endl;
				get_input_date();
				currentDate.SetDate(input_year, input_month, input_day);
				continue;

			case 2:
				std::cout << "=============== [ 2. ���� ���ϱ� ] ===============" << std::endl << std::endl;
				std::cout << "���ϰ� ���� ������ �Է��ϼ���. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					input_not_int();
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
					input_not_int();
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
				std::cout << std::endl;
				if (std::cin.fail()) {
					input_not_int();
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