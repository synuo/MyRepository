#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define MAX 100001
using namespace std;

int n, m, ind[MAX];
vector<pair<int, int>> odr[50004];
vector<int> topo;
vector<int> adj[MAX];
priority_queue<int, vector<int>, greater<int>> q;

bool pos(int k) {
	topo.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		ind[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0, u, v; j < odr[i].size(); j++) {
			tie(u, v) = odr[i][j];
			adj[u].push_back(v);
			ind[v]++;
		}
	}

	
	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) q.push(i);


	while (!q.empty()) {
		int u = q.top(); q.pop();
		topo.push_back(u);
		for (int v : adj[u])
			if (--ind[v] == 0)
				q.push(v);
	}

	return topo.size() == n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

 cin >> n >> m;
	for (int i = 0, q, u; i < m; i++) {
		cin >> q;
		u = 0;
		for (int j = 0, v; j < q; j++) {
			cin >> v;
			if (u != 0) odr[i].push_back({ u,v });
			u = v;
		}
	}

	int lo = 1, hi = m;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (pos(mid))lo = mid;
		else hi = mid - 1;
	}
	pos(lo);
	for (int i : topo) cout << i << " ";
	cout << '\n';

	return 0;
}