#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

int N, D;
int from, to, dist;

vector <int> m(10001, MAX);
vector <pair<int, int>> v[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		cin >> from >> to >> dist;
		if (to > D || to - from < dist) continue;
		v[to].push_back({ from, dist });
	}

	m[0] = 0;

	for (int i = 1; i <= D; i++) {
		m[i] = m[i - 1] + 1;
		for (int j = 0; j < (int)v[i].size(); j++) {
			m[i] = min(m[i], m[v[i][j].first] + v[i][j].second);
		}
	}

	cout << m[D];

	return 0;
}