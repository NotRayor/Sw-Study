#include "LinkedList.h"


// ���� ��� ����
LinkedList* linkedList_create(LinkedList *link, element value) {
	LinkedList *node = NULL;
	node = (LinkedList*)malloc(sizeof(LinkedList));
	
	if (node == NULL)
		printf("create error");

	node->data = value;
	node->link = link;

	return node;
}

// ����Ʈ �� �ڿ� ����
// pthead, �������, ������ ���
void linkedList_add(LinkedList* head, element value) {
	LinkedList *new_node = linkedList_create(NULL, value);
	LinkedList* left_node = head;
	while (left_node->link != NULL) {
		left_node = left_node->link;
	}
	new_node->link = left_node->link;
	left_node->link = new_node;
} 

// ����Ʈ �� �տ� ����
void linkedList_insert(LinkedList* head, element value) {
	LinkedList* new_node = linkedList_create(NULL, value);
	new_node->link = head->link;
	head->link = new_node;
}

// ��� ����
void linkedList_remove(LinkedList* head, int index) {
	LinkedList* remove_node = head->link;
	LinkedList* left_node = head;

	for (int i = 0; i < index; i++) {
		if (head->link == NULL) {
			printf("end \n");
			break;
		}
		left_node = left_node->link;
		remove_node = remove_node->link;
	}
	printf("remove_node : %d \n", remove_node->data);
	left_node->link = remove_node->link;
	free(remove_node);
}

// ��� �湮
void linkedList_print(LinkedList* head) {

	LinkedList* p = head->link;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("end \n");
}

// ��� Ž��
LinkedList *linkedList_search(LinkedList* head, int value) {
	LinkedList* p = head->link;
	
	while (p != NULL) {
		if (p->data == value) {
			return  p;
		}
		p = p->link;
	}
	return p;
}
