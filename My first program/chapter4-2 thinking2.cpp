/*
#include <iostream>

class Point { // ���� ���� ����
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

class Geometry { // ������ ������ ����
	public:
		Geometry() {
			num_points = 0;
		}
		// void addPoint const Point &point ????
		void addPoint(Point &point) {
			point_array[num_points ++] = new Point(point.getX(), point.getY());
		}

		// ��� ���� ���� �Ÿ��� ����ϴ� �Լ��Դϴ�.
		void printDistance();

		// ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ�
		// ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
		// �̶�� �� �� ������ �ٸ� �� �� (x1, y1)�� (x2, y2)�� f(x, y)=0 �� ��������
		// ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
		void printnummeets();

	private:
		// �� 100���� �����ϴ� �迭
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