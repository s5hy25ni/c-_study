#include <iostream>

/*
int input_year, input_month, input_day;

int cheakLeapYear(int year) {
	// 윤년이면
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
	return 1;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
	return 1;
	}
	// 평년이면
	else return 0;
}

void cheakInputError() {
	std::cout << std::endl;
	std::cout << "정수만 입력하세요." << std::endl << std::endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
}
void getInputYear() {
	std::cout << "연도 : ";
	std::cin >> input_year;
}
void getInputMonth() {
	std::cout << "월 : ";
	std::cin >> input_month;
}
void getInputDay() {
	std::cout << "일 : ";
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
			std::cout << "0 이상의 정수를 입력하세요." << std::endl;
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
			std::cout << "1과 12 사이의 정수를 입력하세요." << std::endl;
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
				if (cheakLeapYear(input_year)) { // 윤년이면
					if (1 > input_day || 29 < input_day) {
						std::cout << "윤년입니다. 1과 29 사이의 정수를 입력하세요." << std::endl;
						std::cout << std::endl;
						continue;
					}
				}
				else { // 평년이면
					if (1 > input_day || 28 < input_day) {
						std::cout << "평년입니다. 1과 28 사이의 정수를 입력하세요." << std::endl;
						std::cout << std::endl;
						continue;
					}
				}

			case 4:
			case 6:
			case 9:
			case 11:
				if (1 > input_day || 30 < input_day) {
					std::cout << "1과 30 사이의 정수를 입력하세요." << std::endl;
					std::cout << std::endl;
					continue;
				};

			default:
				if (1 > input_day || 31 < input_day) {
					std::cout << "1과 31 사이의 정수를 입력하세요." << std::endl;
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
	int month_; // 1부터 12까지
	int day_; // 1부터 31까지

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
	std::cout << "현재 날짜 : " << year_ << "-" << month_ << "-" << day_ << std::endl << std::endl;
}

int main() {

	Date currentDate;
	int plus_num, select_num;

	std::cout << "=============== 날짜를 입력해주세요. ===============" << std::endl << std::endl;
	cheakInputDate();
	currentDate.SetDate(input_year, input_month, input_day);

	while (true) {
		std::cout << std::endl;
		std::cout << "=============== 원하는 기능을 선택하세요. ===============" << std::endl << std::endl;
		currentDate.ShowDate();
		std::cout << "1. 현재 날짜 바꾸기" << std::endl;
		std::cout << "2. 연도 더하기" << std::endl;
		std::cout << "3. 월 더하기" << std::endl;
		std::cout << "4. 일 더하기" << std::endl;
		std::cout << "0. 끝내기" << std::endl << std::endl;
		std::cout << "선택 : ";
		std::cin >> select_num;
		std::cout << std::endl;

		if (std::cin.fail()) {
			cheakInputError();
			continue;
		}

		switch (select_num) {
			case 1:
				std::cout << "=============== [ 1. 현재 날짜 바꾸기 ] ===============" << std::endl << std::endl;
				cheakInputDate();
				currentDate.SetDate(input_year, input_month, input_day);
				continue;

			case 2:
				std::cout << "=============== [ 2. 연도 더하기 ] ===============" << std::endl << std::endl;
				std::cout << "더하고 싶은 연수를 입력하세요. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl << std::endl;
					continue;
				}
				currentDate.AddYear(plus_num);
				continue;

			case 3:
				std::cout << "=============== [ 3. 월 더하기 ] ===============" << std::endl;
				std::cout << std::endl;
				std::cout << "더하고 싶은 개월수를 입력하세요. : ";
				std::cin >> plus_num;
				std::cout << std::endl;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl << std::endl;
					continue;
				}
				currentDate.AddMonth(plus_num);
				continue;

			case 4:
				std::cout << "=============== [ 4. 일 더하기 ] ===============" << std::endl << std::endl;
				std::cout << "더하고 싶은 일수를 입력하세요. : ";
				std::cin >> plus_num;
				if (std::cin.fail()) {
					cheakInputError();
				}
				else if (plus_num < 0) {
					std::cout << "더하기만 가능합니다." << std::endl << std::endl;
					continue;
				}
				currentDate.AddDay(plus_num);
				continue;

			case 0:
				std::cout << "=============== 프로그램을 종료합니다. ===============" << std::endl;
				break;

			default:
				std::cout << "0~4번 중에 선택하세요." << std::endl << std::endl;
				continue;
		}
		break;
	}
}

*/