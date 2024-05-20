#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 501;
const int INF = 1e9;
int N, M;
int map[MAX][MAX]; // 0: 안전, 1: 위험, 2: 죽음
int dist[MAX][MAX]; // 최소 생명 소모를 저장
int dy[4] = {1, -1, 0, 0}; // 상하좌우
int dx[4] = {0, 0, 1, -1};

void bfs() {
    deque<pair<int, int>> deq;
    deq.push_back({0, 0});
    dist[0][0] = 0;

    while (!deq.empty()) {
        int x = deq.front().first;
        int y = deq.front().second;
        deq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > 500 || ny > 500) continue;
            if (map[nx][ny] == 2) continue; // 죽음의 구역

            int cost = (map[nx][ny] == 1) ? 1 : 0;

            if (dist[nx][ny] > dist[x][y] + cost) {
                dist[nx][ny] = dist[x][y] + cost;
                if (cost == 1) {
                    deq.push_back({nx, ny});
                } else {
                    deq.push_front({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                map[x][y] = 1; // 위험한 구역
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                map[x][y] = 2; // 죽음의 구역
            }
        }
    }

    // dist 배열을 INF로 초기화
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = INF;
        }
    }

    bfs();

    if (dist[500][500] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dist[500][500] << "\n";
    }

    return 0;
}