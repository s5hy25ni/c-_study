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

    // �� 100 ���� �����ϴ� �迭.
    Point* point_array[100] = {};
    int num_points;

public:
    Geometry() : num_points(0) {}
    ~Geometry() {
        for (int i = 0; i < num_points; i++) {
            if (point_array[i] != nullptr) {
                std::cout << i << "�� ������" << std::endl;
                delete point_array[i];
            }
            else {
                std::cout << i << " : nullptr ��" << std::endl;
            }   
        }
    }

    void AddPoint(Point& point) {
        point_array[num_points++] = new Point(point.getX(), point.getY());
        std::cout << "Add point_array[" << num_points - 1 << "] : ( " << point_array[num_points - 1]->getX() << ", " << point_array[num_points-1]->getY() << " )" << std::endl;
    }

    // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
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
                    std::cout << "Point( " << x1 << ", " << y1 << " )�� Point( " << x2 << ", " << y2 << " )�� �Ÿ� : " << result << std::endl;
                }
            }
        }
        else
        {
            std::cout << "���� 1���ۿ� �����. �� �߰����ּ���." << std::endl;
        }
    };

    // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
    // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
    // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
    // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
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
                std::cout << "���� 2���ۿ� �����. �� �߰����ּ���." << std::endl;
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