#include <iostream>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int value) {
	struct Node* temp = new Node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct Node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->data);
		inorder(root->right);
	}
}

struct Node* insert(struct Node* node, int data) {
	if (node == NULL) {
		return newNode(data);
	}

	if (data < node->data) {
		node->left = insert(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert(node->right, data);
	}

	return node;
}

struct Node* minValueNode(struct Node* node) {
	struct Node* curr = node;

	while (curr && curr->left != NULL) {
		curr = curr->left;
	}

	return curr;
}

struct Node* deleteNode(struct Node* root, int data) {
	if (root == NULL) {
		return root;
	}

	if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else {
		if (root->left == NULL) {
			struct Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			struct Node* temp = root->left;
			delete root;
			return temp;
		}

		struct Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	return 0;
}
