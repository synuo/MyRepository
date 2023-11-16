#include <iostream>
#include <queue>
using namespace std;

int n, m, k, x;
int d[300001];
vector <int> r[300001];

void dijkstra(int s) {
	d[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < r[tmp].size(); i++) {
			int next = r[tmp][i];
			if (d[next] > d[tmp] + 1) {
				d[next] = d[tmp] + 1;
				q.push(next);
			}
		}
	}
}
int main() {

	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		r[s].push_back(e);
	}

	dijkstra(x);

	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			check = true;
			cout << i << '\n';
		}
	}
	if (!check) cout << "-1";

	return 0;
}