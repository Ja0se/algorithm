#pragma warning(disable:4996)
#include <iostream>

using namespace std;
struct node {
	int data;
	char color;
	struct node* left;
	struct node* right;
	struct node* parent;
};
int level;
struct node* nullnode;
void RL(struct node*& root, struct node* x) {
	struct node* l = x->left;
	x->left = l->right;
	if (l->right != nullnode)l->right->parent = x;
	l->parent = x->parent;
	if (x->parent == NULL)root = l;
	else {
		if (x == x->parent->left)x->parent->left = l;
		else x->parent->right = l;
	}
	l->right = x;
	x->parent = l;
}
void LL(struct node*& root, struct node* x) {
	struct node* r = x->right;
	x->right = r->left;
	if (r->left != nullnode)r->left->parent = x;
	r->parent = x->parent;
	if (x->parent == NULL)root = r;
	else {
		if (x == x->parent->left)x->parent->left = r;
		else x->parent->right = r;
	}
	r->left = x;
	x->parent = r;

}

void Insert(struct node* root, int data) {
	struct node* p = new struct node();
	struct node* uncle = root;
	struct node* parent = root;
	struct node* q = root->left;
	p->data = data;
	p->left = nullnode;
	p->right = nullnode;
	p->color = 'R';
	//first input
	if (q == nullnode) {
		p->color = 'B';
		p->parent = root;
		root->left = p;
		root->right = p;
		return;
	}
	while (1) {
		if (q->data > data) {
			if (q->left == nullnode) {
				p->parent = q;
				q->left = p;
				q = q->left;
				break;
			}
			q = q->left;
		}
		else {
			if (q->right == nullnode) {
				p->parent = q;
				q->right = p;
				q = q->right;
				break;
			}
			q = q->right;
		}
	}
	struct node* y;
	while (q != root->left && q->parent->color == 'R') {
		if (q->parent == q->parent->parent->left) {
			y = q->parent->parent->right;
			if (y->color == 'R') {
				q->parent->color = 'B';
				y->color = 'B';
				q->parent->parent->color = 'R';
				q = q->parent->parent;
			}
			else {
				if (q == q->parent->right) {
					q = q->parent;
					LL(root, q);
				}
				q->parent->color = 'B';
				q->parent->parent->color = 'R';
				RL(root, q->parent->parent);
			}
		}
		else {
			y = q->parent->parent->left;
			if (y->color == 'R') {
				q->parent->color = 'B';
				y->color = 'B';
				q->parent->parent->color = 'R';
				q = q->parent->parent;
			}
			else {
				if (q == q->parent->left) {
					q = q->parent;
					RL(root, q);
				}
				q->parent->color = 'B';
				q->parent->parent->color = 'R';
				LL(root, q->parent->parent);
			}
		}
	}
	root->left->color = 'B';
	//afterinsert(root,q);
	//while (1) {
	//	
	//	parent = q->parent;
	//	if (parent == parent->parent->right) {
	//		uncle = parent->parent->left;
	//	}
	//	else uncle = parent->parent->right;

	//	if (q->color=='B'||uncle == parent || q == root->left) {
	//		if (root->left->color == 'R')root->left->color = 'B';
	//		break;
	//	}
	//	if (q->parent->color == 'R' && uncle->color == 'R') {
	//		parent->color = 'B';
	//		uncle->color = 'B';
	//		parent->parent->color = 'R';
	//		q = parent->parent;
	//	}
	//	else if (parent->color == 'R' && uncle->color == 'B') {
	//		// 1.left->right   <  => /
	//		if (parent == parent->parent->left && q == parent->right) {
	//			/*q->parent = grandpa->parent;
	//			if (grandpa->parent == root) {
	//				grandpa->parent->left = q;
	//				grandpa->parent->right = q;
	//			}
	//			else if (grandpa == grandpa->parent->left) {
	//				grandpa->parent->left = q;
	//			}
	//			else {
	//				grandpa->parent->right = q;
	//			}
	//			q->left->parent = parent;
	//			parent->right = q->left;
	//			parent->parent = q;
	//			q->left = parent;
	//			grandpa->parent = q;
	//			q->right->parent = grandpa;
	//			grandpa->left = q->right;
	//			q->right = grandpa;*/
	//			LL(root,parent);
	//			q = q->left;
	//		}
	//		//2.left   >  => /
	//		else if (parent == parent->parent->right && q == parent->right) {
	//			/*parent->parent = grandpa->parent;
	//			if (grandpa->parent == root) {
	//				grandpa->parent->left = q;
	//				grandpa->parent->right = q;
	//			}
	//			else if (grandpa == grandpa->parent->left) {
	//				grandpa->parent->left = parent;
	//			}
	//			else {
	//				grandpa->parent->right = parent;
	//			}
	//			grandpa->right = parent->left;
	//			grandpa->right->parent = grandpa;
	//			grandpa->parent = parent;
	//			parent->left = grandpa;*/
	//			LL(root, q->parent->parent);
	//			q->parent->color = 'B';
	//			q->parent->left->color = 'R';
	//			q = root;
	//		}
	//		//3.right->left   >  =>
	//		else if (parent == parent->parent->right && q == parent->left) {
	//			/*q->parent = grandpa->parent;
	//			if (grandpa->parent == root) {
	//				grandpa->parent->left = q;
	//				grandpa->parent->right = q;
	//			}
	//			else if (grandpa == grandpa->parent->left) {
	//				grandpa->parent->left = q;
	//			}
	//			else {
	//				grandpa->parent->right = q;
	//			}
	//			q->right->parent = parent;
	//			parent->left = q->right;
	//			q->left->parent = grandpa;
	//			grandpa->right = q->left;
	//			q->left = grandpa;
	//			q->right = parent;
	//			parent->parent = q;
	//			grandpa->parent = q;*/
	//			RL(root, parent);
	//			q = q->right;
	//		}
	//		//4.right  <  => 
	//		else {
	//			/*parent->parent = grandpa->parent;
	//			if (grandpa->parent == root) {
	//				grandpa->parent->left = q;
	//				grandpa->parent->right = q;
	//			}
	//			else if (grandpa == grandpa->parent->left) {
	//				grandpa->parent->left = parent;
	//			}
	//			else {
	//				grandpa->parent->right = parent;
	//			}
	//			parent->right->parent = grandpa;
	//			grandpa->left = parent->right;
	//			parent->right = grandpa;
	//			grandpa->parent = parent;*/
	//			RL(root, q->parent->parent);
	//			q->parent->color = 'B';
	//			q->parent->right->color = 'R';
	//			q = root;
	//		}
	//	}
	//	else {
	//		q = parent->parent;
	//		parent = q->parent;
	//		parent->parent = parent->parent;
	//		if (parent == parent->parent->left)uncle = parent->parent->right;
	//		else uncle = parent->parent->left;
	//	}
	//}
}



void Color(struct node*root,int data) {
	struct node* q = root;
	while (1) {
		if (q->data == data) {
			cout << "color(" << data << "): ";
			q->color == 'B' ? cout << "BLACK\n" : cout << "RED\n";
			return;
		}
		else if (q->data > data) {
			q = q->left;
		}
		else {
			q = q->right;
		}
	}

}
//
//void RD(struct node*& root, struct node* x) {
//	struct node* u = NULL;
//	while (x->parent != NULL && x->color == 'B') {
//		if (x == x->parent->left) {//재구축 대상이 부모의 왼쪽 자식
//			u = x->parent->right;//삼촌은 부모의 오른쪽 자식
//			if (u->color == 'R') {//삼촌색 Red
//				u->color = 'B';
//				x->parent->color = 'R';
//				LL(root, x->parent);//x의 부모기준 왼쪽회전
//			}
//			else {//삼촌색 Black
//				if (u->left->color == 'B' && u->right->color == 'B') {//삼촌의 두 자식모두 Black
//					u->color = 'R';
//					x = x->parent;
//				}//삼촌의 자식중 하나라도 Red
//				else {
//					if (u->right->color == 'B') {//삼촌의 오른쪽자식이 Black
//						u->color = 'R';
//						u->left->color = 'B';
//						RL(root, u);//삼촌기준 오른족 회전
//						u = x->parent->right;//새로운 삼촌은 부모의 오른쪽 자식
//					}
//					//삼촌의 오른쪽 자식이 Red
//					u->color = x->parent->color;
//					x->parent->color = 'B';
//					u->right->color = 'B';
//					LL(root, x->parent);//부모기준 왼쪽회전
//					x = root;
//				}
//			}
//		}
//		else {//재구축 대상이 부모의 오른쪽 자식
//			u = x->parent->left;
//			if (u->color == 'R') {//삼촌의 색 Red
//				u->color = 'B';
//				x->parent->color = 'R';
//				RL(root, x->parent);//x의 부모기준 우측회전
//			}
//			else {//삼촌의 색 Black
//				if (u->left->color == 'B' && u->right->color == 'B') {
//					u->color = 'R';
//					x = x->parent;
//				}
//				else {
//					if (u->left->color == 'B') {
//						u->color = 'R';
//						u->right->color = 'B';
//						LL(root, u);
//						u = x->parent->left;
//					}
//					u->color = x->parent->color;
//					x->parent->color = 'B';
//					u->left->color = 'B';
//					RL(root, x->parent);
//					x = root;
//				}
//			}
//		}
//	}
//	x->color = 'B';
//}
void Delete(struct node* root, int data) {
	struct node* q = root->left;
	while (1) {
		if (q->data == data) {
			break;
		}
		else if (q->data > data) {
			q = q->left;
		}
		else {
			q = q->right;
		}
	}
	struct node* y;
	struct node* x;
	if (q->left == nullnode || q->right == nullnode) {//leaf node
		y = q;
	}
	else {
		y = q->right;
		while (y->left != nullnode) {
			y = y->left;
		}
		q->data = y->data;
	}
	if (y->left != nullnode)x = y->left;
	else x = y->right;

	x->parent = y->parent;
	if (y == root->left) {
		/*if (x == nullnode) {
			root->left = nullnode;
			root->right = nullnode;
		}
		else {*/
			root->left = x;
			root->right = x;
		//}
	}
	else {
		if (y == y->parent->left)y->parent->left = x;
		else y->parent->right = x;
	}
	if (y != q) q->data = y->data;

	if (y->color == 'R') {
		return;
	}
	struct node* w;
	while (x->parent!=root&&x->color=='B') {
		if (x == x->parent->left) {//on left child
			w = x->parent->right;
			if (w->color == 'R') {
				w->color = 'B';
				x->parent->color = 'R';
				LL(root, x->parent);
			}
			else {//w==black
				if (w->left->color == 'B' && w->right->color == 'B') {//both black
					w->color = 'R';
					if (x->parent->color == 'R') {
						w->parent->color = 'B';
						x = root->left;
					}
					else {
						x = x->parent;
					}
				}
				else {//either red
					if (w->right->color == 'B') {
						w->color = 'R';
						w->left->color = 'B';
						RL(root, w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 'B';
					w->right->color = 'B';
					LL(root, x->parent);
					x = root->left;
				}
			}
		}
		else {//on right
			w = x->parent->left;
			if (w->color == 'R') {
				w->color = 'B';
				x->parent->color = 'R';
				RL(root, x->parent);
			}
			else {//w==black
				if (w->left->color == 'B' && w->right->color == 'B') {//both black
					w->color = 'R';
					if (x->parent->color == 'R') {
						w->parent->color = 'B';
						x = root->left;
					}
					else {
						x = x->parent;
					}
				}
				else {//either red
					if (w->left->color == 'B') {
						w->color = 'R';
						w->right->color = 'B';
						LL(root, w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 'B';
					w->left->color = 'B';
					RL(root, x->parent);
					x = root->left;
				}
			}
		}
	}
	x->color = 'B';
	root->left->color = 'B';
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("rbt.inp", "r", stdin);
	freopen("rbt.out", "w", stdout);
	nullnode = new struct node();
	nullnode->color = 'B';
	nullnode->left = nullnode->right = nullnode;
	nullnode->parent = NULL;

	struct node* root = new struct node();
	root->data = -1;
	root->left = root->right = nullnode;
	root->parent = root;
	root->color = 'B';

	int cnt = 0;
	while (1) {
		char c;
		int key;
		cin >> c >> key;
		if (key == -1)break;
		switch (c) {
		case 'i':
			Insert(root,key);
			break;
		case 'c':
			Color(root->left, key);
			cnt++;
			break;
		case 'd':
			Delete(root, key);
			break;
		}
	}

	return 0;
}


