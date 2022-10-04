#pragma warning(disable:4996)
#include<iostream>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};
int level = 0;

void Push(int key, struct node* root) {
	struct node* p = new struct node();
	p->data = key;
	p->left = NULL;
	p->right = NULL;
	struct node* q = root->left;
	if (q == NULL) {
		root->left = p;
		return;
	}
	else {
		while (1) {
			if (q->data > key) {
				if (q->left == NULL) {
					q->left = p;
					return;
				}
				else q = q->left;
			}
			else {
				if (q->right == NULL) {
					q->right = p;
					return;
				}
				else q = q->right;
			}
		}
	}
}
void Delete(int key, struct node* root) {
	struct node* p = root->left;
	struct node* q = root;//parent
	while (1) {
		if (p->data == key) {
			break;
		}
		else if (p->data > key) {
			q = p;
			p = p->left;
		}
		else {
			q = p;
			p = p->right;
		}
	}
	if (p->left == NULL && p->right == NULL) {
		
		if (q->left == p)q->left = NULL;
		if (q->right == p) q->right = NULL;
		free(p);
	}
	else if (p->left != NULL && p->right == NULL) {//left
		if (q->left == p)q->left = p->left;
		if (q->right == p)q->right = p->left;
		free(p);
	}
	else if (p->left == NULL && p->right != NULL) {//right
		if (q->left == p)q->left = p->right;
		if (q->right == p) q->right = p->right;
	}
	else {//both
		struct node* r = p->right;
		while (r->left != NULL) {
			q = r;
			r = r->left;
		}
		p->data = r->data;
		if (q->left == r) {
			q->left = r->right;
		}
		if(p->right==r) {
			p->right = r->right;
		}
	}
}
void Level(struct node*p,int cnt) {
	if (cnt > level)level = cnt;
	if (p->left != NULL) {
		Level(p->left, cnt + 1);
	}
	if (p->right != NULL) {
		Level(p->right, cnt + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("bst.inp", "r", stdin);
	freopen("bst.out", "w", stdout);
	struct node* root = new struct node();
	root->data = -1;
	root->left = NULL;
	root->right = NULL;
	while (1) {
		char c;
		int n;
		cin >> c >> n;
		if (n == -1) {
			Level(root, 0);
			cout << level-1;
			return 0;
		}
		if (c == 'i') {
			Push(n,root);
		}
		else {
			Delete(n, root);
		}
	}

	return 0;
}