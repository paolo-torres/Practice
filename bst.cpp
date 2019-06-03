#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Binary Search Tree

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int dataue) {
	struct Node* temp = new Node;
	temp->data = dataue;
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

struct Node* mindataueNode(struct Node* node) {
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

		struct Node* temp = mindataueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

// Find Mode

void traverse(Node* root, map<int, int>& m, vector<int>& max) {
	if (root != NULL) {
		traverse(root->left, m, max);
		auto find = m.find(root->data);
		if (find != m.end()) {
			find->second++;
			if (max[1] < find->second) {
				max[0] = find->first;
				max[1] = find->second;
			}
		}
		else {
			m.insert({ root->data, 1 });
		}
		traverse(root->right, m, max);
	}
}

vector<int> findMode(Node* root) {
	map<int, int> m;
	vector<int> max = { 0, 0 };

	traverse(root, m, max);

	return max;
}

// Lowest Common Ancestor

Node* findLCA(Node* root, Node* p, Node* q) {
	if (p->data < root->data && q->data < root->data) {
		return findLCA(root->left, p, q);
	}
	else if (p->data > root->data && q->data > root->data) {
		return findLCA(root->right, p, q);
	}
	else {
		return root;
	}
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	return findLCA(root, p, q);
}

// Search in a Binary Search Tree

Node* searchBST(Node* root, int val) {
	if (root == NULL) {
		return NULL;
	}

	if (val < root->data) {
		return searchBST(root->left, val);
	}
	else if (val > root->data) {
		return searchBST(root->right, val);
	}
	else {
		return root;
	}
}

// Convert Sorted Array to Binary Search Tree

Node* helper(vector<int> &nums, int low, int high) {
	if (low > high) {
		return NULL;
	}

	int mid = (low + high) / 2;

	Node* node = new Node;
	node->data = nums[mid];

	node->left = helper(nums, low, mid - 1);
	node->right = helper(nums, mid + 1, high);

	return node;
}

Node* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() == 0) {
		return NULL;
	}

	Node* head = helper(nums, 0, nums.size() - 1);

	return head;
}

// Binary Search

int helper_2(vector<int>& nums, int target, int low, int high) {
	if (low > high) {
		return -1;
	}

	int mid = (low + high) / 2;

	if (target < nums[mid]) {
		return helper_2(nums, target, low, mid - 1);
	}
	else if (target > nums[mid]) {
		return helper_2(nums, target, mid + 1, high);
	}
	else {
		return nums[mid];
	}
}

int search(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size() - 1;

	return helper_2(nums, target, low, high);
}

// Univalued Binary Tree

bool isUnivalTree(Node* root) {
	int val = root->data;
	if (root != NULL) {
		isUnivalTree(root->left);
		if (root->data != val) {
			return false;
		}
		isUnivalTree(root->right);
	}

	return true;
}

// Invert Binary Tree

Node* invertTree(Node* root) {
	if (root == NULL) {
		return NULL;
	}

	Node* left = invertTree(root->left);
	Node* right = invertTree(root->right);

	root->left = right;
	root->right = left;

	return root;
}

// Maximum Depth of Binary Tree

int maxDepth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Balanced Binary Tree

int depth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(Node* root) {
	if (root == NULL) {
		return true;
	}

	int left = depth(root->left);
	int right = depth(root->right);

	return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
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
