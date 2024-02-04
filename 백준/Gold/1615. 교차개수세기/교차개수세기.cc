#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

vector <int> v[2001];
vector <int> segtree;

int N, M;
long long ans = 0;

void update(int node, int start, int end, int val) {
	if (start == end) {
		segtree[node] += 1;
		return;
	}
	int mid = (start + end) / 2;
	if (val <= mid) {
		update(node * 2, start, mid, val);
	}
	else {
		update(node * 2 + 1, mid + 1, end, val);
	}
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
	if ((end < left) || (right < start)) {
		return 0;
	}
	if ((left<=start) &&(end <= right)) {
		return segtree[node];
	}
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	int height = (int)ceil(log2(N));
	int size = (1 << (height + 1));
	segtree.resize(size);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j];
			ans += query(1, 1, N, x + 1, N);
		}
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j];
			update(1, 1, N, x);
		}
	}

	cout << ans;

	return 0;
}