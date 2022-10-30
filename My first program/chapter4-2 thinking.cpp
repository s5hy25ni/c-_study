/*

class Point { // ���� ���� ����
	int x, y;

	public:
		Point(int pos_x, int pos_y);
};

class Geometry { // ������ ������ ����
	public:
		Geometry() {
			num_points = 0;
		}

		void AddPoint(const Point& point) {
			point_array[num_points++] = new Point(point.x, point.y);
		}

		// ��� ���� ���� �Ÿ��� ����ϴ� �Լ��Դϴ�.
		void PrintDistance();

		// ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ�
		// ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
		// �̶�� �� �� ������ �ٸ� �� �� (x1, y1)�� (x2, y2)�� f(x, y)=0 �� ��������
		// ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.

		void PrintNumMeets();

	private:
		// �� 100���� �����ϴ� �迭
		Point* point_array[100];
		int num_points;	
};

*/