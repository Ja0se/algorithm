#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long

int m, n, k;
vector<ll> v;
vector<ll> tree;
//세그먼트 트리 생성
ll init(int node, int start, int end) {
	// arr: 초기 배열 
	// tree: 세그먼트 트리 
	// node: 세그먼트 트리 노드 번호 
	// node가 담당하는 합의 범위가 start ~ end

	if (start == end)	return tree[node] = v[start];//노드가 리프 노드인 경우 배열의 그 원소를 가져야 한다.

	int mid = (start + end) / 2;
	//구간합 구하기
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start)	return 0;//겹치지 않으면 탐색할 필요가 없음
	if (left <= start && end <= right)	return tree[node];//탐색하는 구간이 전체 구간을 모두 포함할 경우
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);//왼쪽 구간+오른쪽 구간
}

void update(int node, int start, int end, int index, ll diff) {
	if (index<start || index>end)	return;// index가 구간안에 없는 경우
	tree[node] = tree[node] + diff;
	//리프노드가 아닌 경우 자식도 변경해줘야 하기 때문에
	//리프 노드인지 검사 후 아래 자식 노드를 갱신해준다.
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
	int height = (int)ceil(log2(n));//세그먼트 트리의 높이
	int tree_size = (1 << (height + 1));//세그먼트 트리의 크기
	tree.resize(tree_size);
	init(1, 0, n - 1);

	ll b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//update
			c -= v[b - 1];
			v[b - 1] += c;//diff는 차이만 더해준다.
			update(1, 0, n - 1, b - 1, c);
		}
		else {//print sum
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
