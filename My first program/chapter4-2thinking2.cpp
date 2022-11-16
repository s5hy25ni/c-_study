#include <iostream>
#include <cmath>

class Point {
    int x, y;

public:
    Point(int pos_x, int pos_y) : x(pos_x), y(pos_y) {}
    int getX() { return x; };
    int getY() { return y; };
};

class Geometry {

    // 점 100 개를 보관하는 배열.
    Point* point_array[100] = {};
    int num_points;

public:
    Geometry() : num_points(0) {}
    ~Geometry() {
        for (int i = 0; i < num_points; i++) {
            if (point_array[i] != nullptr) {
                std::cout << i << "가 삭제됨" << std::endl;
                delete point_array[i];
            }
            else {
                std::cout << i << " : nullptr 임" << std::endl;
            }   
        }
    }

    void AddPoint(Point& point) {
        point_array[num_points++] = new Point(point.getX(), point.getY());
        std::cout << "Add point_array[" << num_points - 1 << "] : ( " << point_array[num_points - 1]->getX() << ", " << point_array[num_points-1]->getY() << " )" << std::endl;
    }

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance() 
    {
        if (num_points > 1) 
        {
            for (int i = 0; i < num_points-1; i++) 
            {
                int x1 = point_array[i]->getX();
                int y1 = point_array[i]->getY();
                for (int j = i + 1; j < num_points; j++) 
                {
                    int x2 = point_array[j]->getX();
                    int y2 = point_array[j]->getY();
                    double result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                    std::cout << "Point( " << x1 << ", " << y1 << " )과 Point( " << x2 << ", " << y2 << " )의 거리 : " << result << std::endl;
                }
            }
        }
        else
        {
            std::cout << "점이 1개밖에 없어용. 더 추가해주세용." << std::endl;
        }
    };

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void PrintNumMeets()
        {
            if (num_points > 2)
            {   
                int numMeets = 0;
                for (int i = 0; i < num_points-2; i++)
                {
                    int x1 = point_array[i]->getX();
                    int y1 = point_array[i]->getY();
                    for (int j = i + 1; j < num_points-1; j++)
                    {
                        int x2 = point_array[j]->getX();
                        int y2 = point_array[j]->getY();
                        for (int k = j + 1; k < num_points; k++)
                        {
                            int x3 = point_array[k]->getX();
                            int y3 = point_array[k]->getY();
                        }
                    }
                }
            }
            else
            {
                std::cout << "점이 2개밖에 없어용. 더 추가해주세용." << std::endl;
            }
        }



};

int main() {
    Point x = Point(1, 2);
    Point y = Point(8, 11);
    Point z = Point(2, 5);
    Geometry g = Geometry();
    g.AddPoint(x);
    g.AddPoint(y);
    g.AddPoint(z);
    g.PrintDistance();
}