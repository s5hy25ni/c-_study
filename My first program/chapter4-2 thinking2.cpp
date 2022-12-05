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
        std::cout << std::endl << "<========== 프로그램 종료 ==========>" << std::endl;
        for (int i = 0; i < num_points; i++) {
            if (point_array[i] != nullptr) {
                std::cout << "point_array[" << i << "] 삭제" << std::endl;
                delete point_array[i];
            }
            else {
                std::cout << i << " : nullptr" << std::endl;
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
        std::cout << std::endl << "<=========== 모든 점들 간의 거리를 출력 ==========>" << std::endl;
        std::cout << std::endl << "num_points : " << num_points << std::endl << std::endl;
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
                    std::cout << "Point( " << x1 << ", " << y1 << " )와 Point( " << x2 << ", " << y2 << " )의 거리 : " << result << std::endl;
                }
            }
        }
        else
        {
            std::cout << "점이 1개 이하에용~ 더 추가해주세용 :)" << std::endl;
        }
    };

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void PrintNumMeets()
        {
            std::cout << std::endl << "<========== 모든 점들을 잇는 직선들 간의 교점의 수 출력 ==========>" << std::endl;

            int a1, a2, b1, b2, c1, c2 = 0;
            int lineTotal = 1;

            for (int i = num_points; i > 0; i--) {
                lineTotal *= i;
            }

            int* aArray = new int[lineTotal];
            int* bArray = new int[lineTotal];
            int* cArray = new int[lineTotal];
            int lineNum = 0;
            int intersectionPoint = 0;

            bool notInArray = true;

            if (num_points > 2)
            {
                // 일단 직선의 방정식
                for (int i = 0; i < num_points - 1; i++) 
                {
                    int x1 = point_array[i]->getX();
                    int y1 = point_array[i]->getY();
                    for (int j = i + 1; j < num_points; j++)
                    {
                        int x2 = point_array[j]->getX();
                        int y2 = point_array[j]->getY();
                        
                        a1 = y2 - y1;
                        b1 = -(x2 - x1);
                        c1 = (-b1 * y1) - (a1 * x1);

                        for (int k = 0; k < lineNum; k++) {
                            if (a1 != aArray[k] || b1 != bArray[k] || c1 != cArray[k]) {
                                continue;
                            }
                            else {
                                notInArray = false;
                                break;
                            }
                        }
                
                        if (notInArray) {
                            aArray[lineNum] = a1;
                            bArray[lineNum] = b1;
                            cArray[lineNum] = c1;
                            lineNum++;
                        }
                        else {
                            std::cout << "동일한 방정식이 존재함~!" << std::endl;
                            notInArray = true;
                            continue;
                        }

                        std::cout << "Point( " << x1 << ", " << y1 << " )과 Point( " << x2 << ", " << y2 << " )를 지나는 직선의 방정식 : " << a1 << "x + " << b1 << "y + " << c1 << std::endl;                        
                        
                        for (int m = j + 1; m < num_points; m++) {
                            int x3 = point_array[m]->getX();
                            int y3 = point_array[m]->getY();

                            for (int n = 0; n < m; n++) {
                                int x4 = point_array[n]->getX();
                                int y4 = point_array[n]->getY();

                                a2 = y4 - y3;
                                b2 = -(x4 - x3);
                                c2 = (-b2 * y3) - (a2 * x3);

                                for (int k = 0; k < lineNum; k++) {
                                    if (a2 != aArray[k] || b2 != bArray[k] || c2 != cArray[k]) {
                                        continue;
                                    }
                                    else {
                                        notInArray = false;
                                        break;
                                    }
                                }

                                if (notInArray) {
                                    aArray[lineNum] = a2;
                                    bArray[lineNum] = b2;
                                    cArray[lineNum] = c2;
                                    lineNum++;
                                }
                                else {
                                    std::cout << "동일한 방정식이 존재함~!" << std::endl;
                                    notInArray = true;
                                    continue;
                                }

                                if (((a1 * x3) + (b1 * y3) + c1) * ((a1 * x4) + (b1 * y4) + c1) <= 0) ++intersectionPoint;                               

                            }
                        }
                    }
                }

                std::cout << "교점의 수는 " << intersectionPoint << "개 입니당~ :)" << std::endl;
            }
            else
            {
                std::cout << "점이 2개 이하에용~ 더 추가해주세용 :)" << std::endl;
            }

            delete[] aArray;
            delete[] bArray;
            delete[] cArray;
        }



};

int main() {
    Point x = Point(1, 2);
    Point y = Point(-3, 5);
    Point z = Point(5, -4);
    Point k = Point(-5, -1);
    Point m = Point(2, 4);

    Geometry g = Geometry();
    g.AddPoint(x);
    g.AddPoint(y);
    g.AddPoint(z);
    g.AddPoint(k);
    g.AddPoint(m);
    g.PrintDistance();
    g.PrintNumMeets();
}
