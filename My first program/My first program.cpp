// My first program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// #include <iostream>
// #include "header1.h"
// #include "header2.h"

/* namespace {
	int OnlyInThisFile() {
		return 0;
	}
	int only_in_this_file = 0;
} */

// using namespace header1;

 // int main() {
	/* for문 예제
	int sum = 0;

	for (int i = 1; i <= 10; i++) {
		sum += i;
	}

	std::cout << "합은 : " << sum << std::endl;
	*/

	/* while문 예제 
	int i = 1, sum = 0;
	
	while (i <= 10) {
		sum += i;
		i++;
	}

	std::cout << "합은 : " << sum << std::endl;
	*/

	/* if - else문

	int lucky_number = 3;
	std::cout << "비밀 숫자를 맞춰 보세요!" << std::endl;

	int user_input;

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "정답입니다!" << std::endl;
			break;
		}
		else {
			std::cout << "오답입니다, 다시 생각해보세요!" << std::endl;
		}
	}
	 */


		/* switch문

		int user_input;
		std::cout << "어떤 정보가 궁금하신가요?" << std::endl;
		std::cout << "1. 이름 " << std::endl;
		std::cout << "2. 나이 " << std::endl;
		std::cout << "3. 성별 " << std::endl;
		std::cin >> user_input;

		switch (user_input) {
			case 1:
				std::cout << "s5hy25ni" << std::endl;
				break;
			case 2:
				std::cout << "27살" << std::endl;
				break;
			case 3:
				std::cout << "여자" << std::endl;
				break;
			default:
				std::cout << "1~3번을 입력하세요." << std::endl;
				break;
		}
		*/

//	}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
