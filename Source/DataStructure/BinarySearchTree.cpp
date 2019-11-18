#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int value;
	struct NodeStruct* left;
	struct NodeStruct* right;
}Node;

Node* root = NULL;

Node* BST_insert(Node* root, int value) {

	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->left = root->right = NULL;
		root->value = value;
		return root;
	}
	else {
		// ��Ʈ���� ���� ���� ���� ���
		if (root->value > value) {
			root->left = BST_insert(root->left, value);
		}
		// ���� ���� Ŭ ���
		else {
			root->right = BST_insert(root->right, value);
		}
	}
	return root;
}


Node* findMinNode(Node* root) {
	Node* temp = root;
	
	// ����Ʈ���� �� ���� ��带 ã�´�.
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* findMaxNode(Node* root) {
	Node* temp = root;

	// ����Ʈ���� �� ������ ��带 ã�´�.
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

Node* BST_delete(Node* root, int value) {
	Node* temp = NULL;
	
	// �������
	if (root == NULL) {
		return NULL;
	}

	// ��Ʈ �� ���� ã�� ���� ���� ���
	if (root->value > value) {
		root->left = BST_delete(root->left, value);
	}
	// ã�� ���� ū ���
	else if(root->value < value){
		root->right = BST_delete(root->right, value);
	}
	// ������ ��� Ȯ��
	else {
		// �ڽ� ��尡 �� �� �ִ� ���
		if (root->left != NULL && root->right != NULL) {
			temp = findMinNode(root->right);
			root->value = temp->value;
			root->right = BST_delete(root->right, temp->value);
		}
		// �� �� ���� ���� ���
		else {
			temp = (root->left == NULL) ? root->right : root->left;
			free(root);
			return temp; 
		}

	}

	return root;
}

Node* BST_search(Node* root, int value) {
	if (root == NULL)
		return NULL;

	// ã�� ���� ��Ʈ �� ���� �۴ٸ�
	if (root->value > value) {
		root->left = BST_search(root->left, value);
	}
	// ũ�ٸ�
	else if(root->value < value){
		root->right = BST_search(root->right, value);
	}
	// ��Ʈ ���� ã�� ���̶��,
	else {
		return root;
	}

}

Node* BST_inorder(Node* root) {
	if (root == NULL)
		return NULL;

	BST_inorder(root->left);
	printf("%d ", root->value);
	BST_inorder(root->right);
}

int main() {
	Node* root = NULL;
	root = BST_insert(root, 4);
	root = BST_insert(root, 10);
	root = BST_insert(root, 9);
	root = BST_insert(root, 8);
	root = BST_insert(root, 7);
	root = BST_insert(root, 13);
	root = BST_insert(root, 2);

	BST_inorder(root);
}










