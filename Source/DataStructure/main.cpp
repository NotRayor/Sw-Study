#include "ArrayList.h"
#include "LinkedList.h"

int main() {
	ArrayList m_arrayList;

	arrayList_init(&m_arrayList);
	arrayList_add(&m_arrayList, 0, 10);
	arrayList_add(&m_arrayList, 0, 20);
	arrayList_add(&m_arrayList, 0, 30);
	arrayList_add(&m_arrayList, 0, 40);

	arrayList_print(&m_arrayList);

	// �̷��� �����ϴϱ� �ڷ� �и���,

	LinkedList* m_linkedList = linkedList_create(NULL, 0);

	linkedList_add(m_linkedList, 10);
	linkedList_add(m_linkedList, 20);
	linkedList_add(m_linkedList, 30);
	linkedList_remove(m_linkedList, 0);
	LinkedList* getNode = linkedList_search(m_linkedList, 20);
	printf("���� getNode Value : %d \n", getNode->data);

	linkedList_print(m_linkedList);


}