#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 40


typedef struct ArrayList_t {
	int* link;
	int length;
}ArrayList;

// �ʱ�ȭ �Լ�
void arrayList_init(ArrayList* L);

// ����� �� �˻�
int arrayList_isfull(ArrayList* L);


// index, ���� ��ġ  value ���� ��
void arrayList_add(ArrayList* L, int index, int value);

// index ������ ���
void arrayList_remove(ArrayList* L, int index);


void arrayList_print(ArrayList* L);

