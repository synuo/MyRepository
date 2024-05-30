#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> v;
int dist[501];

void bellmanFord(int n) {
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < v.size(); pos++) {
            int from = v[pos].first.first;
            int to = v[pos].first.second;
            int cost = v[pos].second;

            if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
        }
    }

    for (int pos = 0; pos < v.size(); pos++) {
        int from = v[pos].first.first;
        int to = v[pos].first.second;
        int cost = v[pos].second;
        if (dist[from] + cost < dist[to]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

}


int main() {

    int tc; cin >> tc;

    while (tc--) {
        v.clear();
        int n, m, w; cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) dist[i] = 987654321;

        for (int i = 0; i < m; i++) {
            int from, to, cost; cin >> from >> to >> cost;
            v.push_back({ {from,to},cost });
            v.push_back({ {to,from},cost });
        }
        for (int i = 0; i < w; i++) {

            int from, to, cost; cin >> from >> to >> cost;
            v.push_back({ {from,to},-cost });
        }

        bellmanFord(n);
    }


    return 0;
}