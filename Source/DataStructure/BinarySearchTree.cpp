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
		// 루트보다 삽입 값이 작을 경우
		if (root->value > value) {
			root->left = BST_insert(root->left, value);
		}
		// 삽입 값이 클 경우
		else {
			root->right = BST_insert(root->right, value);
		}
	}
	return root;
}


Node* findMinNode(Node* root) {
	Node* temp = root;
	
	// 이진트리의 맨 왼쪽 노드를 찾는다.
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* findMaxNode(Node* root) {
	Node* temp = root;

	// 이진트리의 맨 오른쪽 노드를 찾는다.
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

Node* BST_delete(Node* root, int value) {
	Node* temp = NULL;
	
	// 기저사례
	if (root == NULL) {
		return NULL;
	}

	// 루트 값 보다 찾는 값이 작은 경우
	if (root->value > value) {
		root->left = BST_delete(root->left, value);
	}
	// 찾는 값이 큰 경우
	else if(root->value < value){
		root->right = BST_delete(root->right, value);
	}
	// 삭제할 노드 확인
	else {
		// 자식 노드가 둘 다 있는 경우
		if (root->left != NULL && root->right != NULL) {
			temp = findMinNode(root->right);
			root->value = temp->value;
			root->right = BST_delete(root->right, temp->value);
		}
		// 둘 다 있지 않은 경우
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

	// 찾는 값이 루트 값 보다 작다면
	if (root->value > value) {
		root->left = BST_search(root->left, value);
	}
	// 크다면
	else if(root->value < value){
		root->right = BST_search(root->right, value);
	}
	// 루트 값이 찾는 값이라면,
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










