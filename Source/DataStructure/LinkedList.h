#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;

typedef struct LinkedList_t {
	LinkedList_t* link;
	element data;

}LinkedList;

// 동적 노드 생성
LinkedList* linkedList_create(LinkedList* link, element value);

// 노드 삽입
// pthead, 이전노드, 삽입할 노드
void linkedList_add(LinkedList* head, element value);

// 노드 삭제
void linkedList_remove(LinkedList* head, int index);

// 노드 방문
void linkedList_print(LinkedList* head);

// 노드 탐색
LinkedList* linkedList_search(LinkedList* head, int value);