#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
const int MAX_V=101;
int n,m,a,b,c,cycle=0;
vector<pair<int,int>> adj[MAX_V];
vector<int> rev[MAX_V];
int dist[MAX_V],pre[MAX_V],vis[MAX_V];

void bellman_ford(int st){
    fill(dist, dist+MAX_V, INT_MAX);
    fill(pre, pre+MAX_V, 0);
    dist[st]=0;
    for(int iter=1; iter<=n; iter++){
        //모든 간선 확인작업을 n번 반복
        for(int cur=1; cur<=n; cur++){
            if(dist[cur]==INT_MAX) continue; //아직 이어지지 않은 정점은 패스
            for(auto &u:adj[cur]){
                int next=u.first, cost=u.second;
                if(dist[next]>dist[cur]+cost){
                    dist[next]=dist[cur]+cost;
                    pre[next]=cur; //경로저장
                    if(iter==n && vis[next]) cycle=1; //사이클이 있고 n번 노드까지 가는 길이 있으면 -1출력
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, -c});
        rev[b].push_back(a); //경로를 거꾸로 저장
    }

    //n에서 부터 출발해서 경로를 거스르며 vis체크 -> i번 노드에서 n번노드까지 갈 수 있다면 vis[i]=1
    queue<int> q;
    q.push(n);
    vis[n]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0; i<rev[cur].size(); i++){
            int next=rev[cur][i];
            if(!vis[next]){
                vis[next]=1;
                q.push(next);
            }
        }
    } 

    bellman_ford(1);

    if(cycle){
        cout<<-1;
    }
    else{
        vector<int> ans;
        int idx = n;
        while (idx >= 1) {
            ans.push_back(idx);
            idx = pre[idx];
        }
        reverse(ans.begin(), ans.end());
        for (auto &k:ans) cout << k << " ";
    }
    return 0;
}