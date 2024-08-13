#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
bool visit1[1001];
bool visit2[1001];
int grp[1001][1001];
queue <int> q;

void dfs(int x) {
	visit1[x] = 1;
	cout << x << " ";
	for (int i = 1; i <= N; i++) {
		if (grp[x][i] == 1 && visit1[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int x) {
	q.push(x);
	visit2[x] = 1;
	cout << x << " ";

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (grp[x][i] == 1 && visit2[i] == 0) {
				q.push(i);
				visit2[i] = 1;
				cout << i << " ";
			}
		}
	}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	 cin >> N >> M >> V;

	 for (int i = 0; i < M; i++) {
		 int a, b; cin >> a >> b;
		 grp[a][b] = 1;
		 grp[b][a] = 1;
	 }

	 dfs(V);
	 cout << "\n";

	 bfs(V);
	 cout << "\n";
	 
	return 0;
}