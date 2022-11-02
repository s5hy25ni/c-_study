/*
#include <iostream>

class Point { // 점에 관한 정보
	int x, y;

	public:

		Point(int pos_x, int pos_y);
		
		int getX() { return x; }
		int getY() { return y; }

};

Point::Point(int pos_x, int pos_y) {
	x = pos_x;
	y = pos_y;
}

class Geometry { // 점들을 가지고 연산
	public:
		Geometry() {
			num_points = 0;
		}
		// void addPoint const Point &point ????
		void addPoint(Point &point) {
			point_array[num_points ++] = new Point(point.getX(), point.getY());
		}

		// 모든 점들 간의 거리를 출력하는 함수입니다.
		void printDistance();

		// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수
		// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
		// 이라고 할 때 임의의 다른 두 점 (x1, y1)과 (x2, y2)가 f(x, y)=0 을 기준으로
		// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
		void printnummeets();

	private:
		// 점 100개를 보관하는 배열
		Point* point_array[100];
		int num_points;	
};

void Geometry::printDistance() {
	for (int i = 0; i <= num_points; i++) {
		std::cout << i << std::endl;
		std::cout << num_points << " : " << std::endl;
		std::cout << point_array[i] << std::endl;
	}
}

int main() {
	Point p1(1, 3);
	Geometry g1;
	g1.addPoint(p1);
	g1.printDistance();
}
*/