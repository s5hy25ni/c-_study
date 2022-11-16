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
//    // 점 100 개를 보관하는 배열.
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
//    // 모든 점들 간의 거리를 출력하는 함수 입니다.
//    void PrintDistance() {
//        for (int i = 1; i < num_points; i++) {
//            for (int j = i + 1; j <= num_points; j++) {
//
//            }
//        }
//    };
//
//    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
//    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
//    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
//    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
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