//#include <iostream>
//
//class Point {
//    int x, y;
//
//public:
//    Point(int pos_x, int pos_y) : x(pos_x), y(pos_y) {}
//    int getX() { return x; };
//    int getY() { return y; };
//};
//
//class Geometry {
//
//    // �� 100 ���� �����ϴ� �迭.
//    Point* point_array[100] = {};
//    int num_points;
//
//public:
//    Geometry() : num_points(0) {}
//    ~Geometry() {
//        delete[] point_array;
//    }
//
//    void AddPoint(Point& point) {
//        point_array[num_points++] = new Point(point.getX(), point.getY());
//        std::cout << point_array[num_points] << std::endl;
//    }
//
//    // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
//    void PrintDistance() {
//        for (int i = 1; i < num_points; i++) {
//            for (int j = i + 1; j <= num_points; j++) {
//
//            }
//        }
//    };
//
//    // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
//    // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
//    // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
//    // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
//    void PrintNumMeets() {}
//
//
//
//};
//
//int main() {
//    Point x = Point(1, 2);
//    Geometry y = Geometry();
//    y.AddPoint(x);
//}