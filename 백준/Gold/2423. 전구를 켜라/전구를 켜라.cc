#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M;
int k = 501; //x,y 좌표 상한값
char way;
const int MAX_V = 300001;
vector <pair<int, int>> adj[MAX_V];
priority_queue <pair<int, int>, vector <pair<int, int>>, greater<>> pq;

int dijkstra(int st, int ed) {
    int dist[MAX_V];
    fill(dist, dist + MAX_V, INT_MAX);
    int visited[MAX_V] = { 0 };
    
    dist[st] = 0;
    pq.push({ 0,st });
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue; //이미 방문한 곳이면 무시
        visited[cur] = 1;

        for (auto& u : adj[cur]) {
            int next = u.first, cost = u.second;
            int next_dist = dist[cur] + cost;
            if (dist[next] > next_dist) { //최단 거리 갱신
                dist[next] = next_dist; 
                pq.push({ dist[next], next });
            }
        }
    }

    return dist[ed];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    string s;
    int sol;

    //꼭짓점 기준 (0,0)에서 (n,m)까지 가는 최단 경로
    // <간선 모델링>
    //  - 타일을 회전시키지 않아도 만들어지는 연결은 가중치 0
    //  - 타일을 회전시켜야 만들어지는 연결은 가중치 1
    //0에서 시작하여 (k+1)*n + m 까지의 최단거리 다익스트라

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '/') {
                adj[i * k + j].push_back({ (i + 1) * k + (j + 1), 1});
                adj[(i + 1) * k + (j + 1)].push_back({ i * k + j,1 });
                adj[(i + 1) * k + j].push_back({ i * k + (j + 1),0 });
                adj[i * k + (j + 1)].push_back({ (i + 1) * k + j,0 });
            }
            else {
                adj[i * k + j].push_back({ (i + 1) * k + (j + 1),0 });
                adj[(i + 1) * k + (j + 1)].push_back({ i * k + j,0 });
                adj[(i + 1) * k + j].push_back({ i * k + (j + 1),1 });
                adj[i * k + (j + 1)].push_back({ (i + 1) * k + j,1 });
            }
        }
    }

    sol = dijkstra(0, N * k + M);

    if (sol == INT_MAX) cout << "NO SOLUTION";
    else cout << sol;

    return 0;
}
