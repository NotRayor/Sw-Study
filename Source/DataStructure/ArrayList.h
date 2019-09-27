#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 40


typedef struct ArrayList_t {
	int* link;
	int length;
}ArrayList;

// 초기화 함수
void arrayList_init(ArrayList* L);

// 비었는 지 검사
int arrayList_isfull(ArrayList* L);


// index, 삽입 위치  value 삽입 값
void arrayList_add(ArrayList* L, int index, int value);

// index 삭제할 노드
void arrayList_remove(ArrayList* L, int index);


void arrayList_print(ArrayList* L);

