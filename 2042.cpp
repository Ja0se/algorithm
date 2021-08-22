#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long

int m, n, k;
vector<ll> v;
vector<ll> tree;
//���׸�Ʈ Ʈ�� ����
ll init(int node, int start, int end) {
	// arr: �ʱ� �迭 
	// tree: ���׸�Ʈ Ʈ�� 
	// node: ���׸�Ʈ Ʈ�� ��� ��ȣ 
	// node�� ����ϴ� ���� ������ start ~ end

	if (start == end)	return tree[node] = v[start];//��尡 ���� ����� ��� �迭�� �� ���Ҹ� ������ �Ѵ�.

	int mid = (start + end) / 2;
	//������ ���ϱ�
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start)	return 0;//��ġ�� ������ Ž���� �ʿ䰡 ����
	if (left <= start && end <= right)	return tree[node];//Ž���ϴ� ������ ��ü ������ ��� ������ ���
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);//���� ����+������ ����
}

void update(int node, int start, int end, int index, ll diff) {
	if (index<start || index>end)	return;// index�� �����ȿ� ���� ���
	tree[node] = tree[node] + diff;
	//������尡 �ƴ� ��� �ڽĵ� ��������� �ϱ� ������
	//���� ������� �˻� �� �Ʒ� �ڽ� ��带 �������ش�.
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}

}

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> k;
	ll a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	int height = (int)ceil(log2(n));//���׸�Ʈ Ʈ���� ����
	int tree_size = (1 << (height + 1));//���׸�Ʈ Ʈ���� ũ��
	tree.resize(tree_size);
	init(1, 0, n - 1);

	ll b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//update
			c -= v[b - 1];
			v[b - 1] += c;//diff�� ���̸� �����ش�.
			update(1, 0, n - 1, b - 1, c);
		}
		else {//print sum
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}