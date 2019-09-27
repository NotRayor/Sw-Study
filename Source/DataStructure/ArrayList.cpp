#include "ArrayList.h"
#define MAX_ARRAY_SIZE 40


// �ʱ�ȭ �Լ�
void arrayList_init(ArrayList* L) {
	L->link = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
	L->length = 0;
}

int arrayList_isfull(ArrayList* L) {
	return L->length == MAX_ARRAY_SIZE;
}

// index, ���� ��ġ  value ���� ��
void arrayList_add(ArrayList* L, int index, int value) {
	if (!arrayList_isfull(L) && 0 <= index && index <= L->length){
		// ��� �̵� �۾�
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

// index ������ ���
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

