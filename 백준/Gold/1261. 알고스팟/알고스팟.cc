#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int N, M, ans;
int map[101][101];
int dist[101][101];
int dy[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

struct Info {
	int x, y, sum;
};

void bfs() {
	deque <pair<int, int>> deq;
	deq.push_back({ 0,0 });
	dist[0][0] = 0;
	while (!deq.empty()){
		int x = deq.front().first;
		int y = deq.front().second;
		deq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dy[i][0];
			int ny = y + dy[i][1];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					deq.push_back({ nx,ny });
				}
			} else if (map[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					deq.push_front({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			dist[i][j] = 987654321;
			map[i][j] = str[j] - '0';
		}
	}
	bfs();
	cout << dist[M - 1][N - 1] << "\n";
	return 0;
}