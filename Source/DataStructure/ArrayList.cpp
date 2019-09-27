#include "ArrayList.h"
#define MAX_ARRAY_SIZE 40


// 초기화 함수
void arrayList_init(ArrayList* L) {
	L->link = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
	L->length = 0;
}

int arrayList_isfull(ArrayList* L) {
	return L->length == MAX_ARRAY_SIZE;
}

// index, 삽입 위치  value 삽입 값
void arrayList_add(ArrayList* L, int index, int value) {
	if (!arrayList_isfull(L) && 0 <= index && index <= L->length){
		// 노드 이동 작업
		for (int i = L->length - 1; i >= index; i--) {
			L->link[i + 1] = L->link[i];
		}
		L->link[index] = value;
		L->length++;
	}
	else {
		printf("input error \n");
	}
}

// index 삭제할 노드
void arrayList_remove(ArrayList* L, int index) {
	int temp = 0;

	if (L->length != 0 && 0 <= index && index <= L->length) {
		for (int i = index; i < L->length; i++) {
			L->link[i] = L->link[i + 1];
		}
		L->length--;
	}
	else {
		printf("remove error \n");
	}
}

void arrayList_print(ArrayList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->link[i]);
	}
}

