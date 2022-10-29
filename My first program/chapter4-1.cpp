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
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
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
	int month_; // 1부터 12까지
	int day_; // 1부터 31까지
	
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
			std::cout << "현재 날짜는 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << std::endl;
		}
}; 

int select_num, input_year, input_month, input_day;

void input_not_int() {
	std::cout << "정수만 입력하세요." << std::endl;;
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

void get_input_year() {
	std::cout << "연도 : ";
	std::cin >> input_year;
}
void get_input_month() {
	std::cout << "월 : ";
	std::cin >> input_month;
}
void get_input_day() {
	std::cout << "일 : ";
	std::cin >> input_day;
}

int main() {

	Date inputDate;

	for (;;) {
		std::cout << "원하는 기능을 선택하세요." << std::endl;
		std::cout << "1. 날짜 입력하기" << std::endl;
		std::cout << "2. 연도 더하기" << std::endl;
		std::cout << "2. 월 더하기" << std::endl;
		std::cout << "3. 일 더하기" << std::endl;
		std::cout << "0. 끝내기" << std::endl;
		std::cin >> select_num;

		switch (input_year) {
			case NULL :
				std::cout << "날짜 정보가 존재하지 않습니다. [1. 날짜 입력하기]로 이동합니다." << std::endl;
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
			std::cout << "0 이상의 정수를 입력하세요." << std::endl;
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
			std::cout << "1과 12 사이의 정수를 입력하세요." << std::endl;
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
						std::cout << "1과 30 사이의 정수를 입력하세요." << std::endl;
						continue;
					}

				case 2 :
					if (1 <= input_day && input_day <= 28) {
						inputDate.SetDate(input_year, input_month, input_day);
						inputDate.ShowDate();
					}
					else {
						std::cout << "1과 28 사이의 정수를 입력하세요." << std::endl;
						continue;
					}
				default :
					if (1 <= input_day && input_day <= 31) {
						inputDate.SetDate(input_year, input_month, input_day);
						inputDate.ShowDate();
					}
					else {
						std::cout << "1과 31 사이의 정수를 입력하세요." << std::endl;
						continue;
					}
			}
		break;
		}
	}
}