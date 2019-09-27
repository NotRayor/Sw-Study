#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;

typedef struct LinkedList_t {
	LinkedList_t* link;
	element data;

}LinkedList;

// ���� ��� ����
LinkedList* linkedList_create(LinkedList* link, element value);

// ��� ����
// pthead, �������, ������ ���
void linkedList_add(LinkedList* head, element value);

// ��� ����
void linkedList_remove(LinkedList* head, int index);

// ��� �湮
void linkedList_print(LinkedList* head);

// ��� Ž��
LinkedList* linkedList_search(LinkedList* head, int value);