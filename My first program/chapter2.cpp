#include <iostream>

/* 참조자의 도입 
int change_val(int *p) {
	*p = 3;
	return 0;
}

int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}

int main() {
	int a = 3;
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

}
*/

/* 함수 인자로 레퍼런스 받기
int change_val(int &p) {
	p = 3;
	return 0;
}

int main() {
	int number = 5;
	
	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}
 */

/* 참조자 이해하기 
int main() {
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

	y = 2;
	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

	z = 3;
	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

}
*/

/* 상수에 대한 참조자 
int main() {
	// int &ref = 4; -> error
	const int& ref = 4;
	std::cout << ref << std::endl;
}
*/

/* 배열들의 레퍼런스
int main() {
	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
}
 */

/* 레퍼런스를 리턴하는 함수
// error
int function() {
	int a = 2;
	return a;
}

int main() {
	int b = function();
	return 0;
}
*/

/* 외부 변수의 레퍼런스를 리턴 */
int& function(int& a) {
	a = 5;
	return a;
}
int main() {
	int b = 2;
	int c = function(b);
	return 0;
}