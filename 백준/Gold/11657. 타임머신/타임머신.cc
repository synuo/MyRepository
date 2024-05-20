#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#define INF 2100000000
using namespace std;

int N,M; //N개의 도시, M개의 버스 
int x,y,z;
long long dist[501];
bool cycle;

vector <pair<int,int>> edge[501];

void solve(){
    for(int i=0;i<=N;i++){
        dist[i]= INF;
    }
    dist[1]=0; //시작 정점 1

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=0;j<edge[i].size();j++){
                int next = edge[i][j].first;
                int nextcost = edge[i][j].second;
                if(dist[i]!=INF && dist[next]>dist[i]+nextcost){
                    dist[next]=dist[i]+nextcost;
                    if(k==N) cycle = true;
                }
            }
        }
    }

    if (cycle) cout<<-1;
    else{
        for(int i=2;i<=N;i++){
            cout<<(dist[i] != INF ? dist[i] : -1) << '\n';
        }
    }

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        edge[x].push_back({y,z});
    }

    solve();

    return 0;
}
