class Array {
	const int dim; // 몇 차원 배열인지 -> Array의 차원을 정하면 변경할 수 없음
	int* size; // size[0] * size[1] * ... * size[dim-1] 짜리 배열

	struct Address {
		int level;
		// 맨 마지막 레벨(dim-1 레벨)은 데이터 배열을 가리키고,
		// 그 위 상위 레벨에서는 다음 Address 배열을 가리킨다.
		void* next;
	};

	Address* top;

	void initialize_address(Address* current) {
		if (!current) return; // current 가 NULL 일 때 예외적으로 처리
		if (current->level == dim - 1) { // 재귀 호출 종료 조건 :  Address 배열의 레벨이 (dim - 1)인 경우
			current->next = new int[size[current->level]]; // (dim-1) 레벨의 Address 들의 next에는 int 배열의 데이터가 들어감
			return;
		}
		current->next = new Address[size[current->level]];
		for(int i = 0; i != size[current->level]; i++) {// 재귀 호출이 다음 단계로 넘어가는 과정
			// (static_cast<Address *>(current->next) + i) : current->next 를 시작 주소로 하는 Address 배열의 i 번째 원소를 가리키는 포인터
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

		// 내용물 복사
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