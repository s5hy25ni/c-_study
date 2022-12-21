class Array {
	const int dim; // �� ���� �迭���� -> Array�� ������ ���ϸ� ������ �� ����
	int* size; // size[0] * size[1] * ... * size[dim-1] ¥�� �迭

	struct Address {
		int level;
		// �� ������ ����(dim-1 ����)�� ������ �迭�� ����Ű��,
		// �� �� ���� ���������� ���� Address �迭�� ����Ų��.
		void* next;
	};

	Address* top;

	void initialize_address(Address* current) {
		if (!current) return; // current �� NULL �� �� ���������� ó��
		if (current->level == dim - 1) { // ��� ȣ�� ���� ���� :  Address �迭�� ������ (dim - 1)�� ���
			current->next = new int[size[current->level]]; // (dim-1) ������ Address ���� next���� int �迭�� �����Ͱ� ��
			return;
		}
		current->next = new Address[size[current->level]];
		for(int i = 0; i != size[current->level]; i++) {// ��� ȣ���� ���� �ܰ�� �Ѿ�� ����
			// (static_cast<Address *>(current->next) + i) : current->next �� ���� �ּҷ� �ϴ� Address �迭�� i ��° ���Ҹ� ����Ű�� ������
			(static_cast<Address*>(current->next) + 1)->level = current->level + 1;

			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}

	void delete_address(Address* current) {
		if (!current) return;
		for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
			delete_address(static_cast<Address*>(current->next) + i);
		}

		if (current->level == dim - 1) {
			delete[] static_cast<int*>(current->next);
		}

		delete[] static_cast<Address*>(current->next);
	}

public:
	Array(int dim, int* array_size) : dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);
	}

	Array(const Array& arr) : dim(arr.dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] == arr.size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);

		// ���빰 ����
		copy_address(top, arr.top);
	}

	void copy_address(Address* dst, Address* src) {
		if (dst->level == dim - 1) {
			for (int i = 0; i < size[dst->level]; ++i)
				static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
			return;
		}
		for (int i = 0; i != size[dst->level]; i++) {
			Address* new_dst = static_cast<Address*>(dst->next) + i;
			Address* new_src = static_cast<Address*>(src->next) + i;
			copy_address(new_dst, new_src);
		}
	}
	~Array() {
		delete_address(top);
		delete[] size;
	}
};