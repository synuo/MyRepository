#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//인접한 빈칸으로의 이동은 1초
//벽에 인접한 빈칸에서 벽에 인접한 빈칸으로의 이동은 0초

int H,W; //행(높이), 열(너비)
vector<string> map; // 맵
vector<vector<int>> dist; // 시간 저장
int dy[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };  //상하좌우 방향

//벽에 인접한 칸인지 확인
bool isnearwall(int x, int y){
    for (int i = 0; i < 4; i++) { 
		int nx = x + dy[i][0];
		int ny = y + dy[i][1];
		if (nx >= 0 && ny >= 0 && nx < H && ny < W && map[nx][ny] == '#') {
            return true;
        } 
	}
    return false;
}

//0-1 bfs
void bfs(int sx, int sy) {
    deque <pair<int, int>> deq;
    deq.push_back({sx, sy});
    dist[sx][sy] = 0;

	while (!deq.empty()){
		int x = deq.front().first;
		int y = deq.front().second;
		deq.pop_front();

        bool nowflag = isnearwall(x,y);
		for (int i = 0; i < 4; i++) { 
			int nx = x + dy[i][0];
			int ny = y + dy[i][1];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;  //범위 체크
            if (map[nx][ny]=='#') continue; //가는 위치가 길인지 체크

            bool nextflag = isnearwall(nx,ny);
            if(nowflag && nextflag){   //인접한 벽에서 인접한 벽으로의 이동이면
                if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					deq.push_front({ nx,ny });
				}

            }else{
                if (dist[nx][ny] > dist[x][y]+1) {
					dist[nx][ny] = dist[x][y]+1;
					deq.push_back({ nx,ny });
				}
            }
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin>>H>>W;
    map.resize(H);
    dist.assign(H, vector<int>(W, 987654321)); 

    int startx, starty;
    int endx, endy;
    for(int i=0;i<H;i++){  
        cin >> map[i];  
		for (int j = 0; j < W; j++) {
            if(map[i][j]=='S'){
                startx=i; starty=j;
            }else if(map[i][j]=='E'){
                endx=i; endy=j;
            }
		}
    }

    bfs(startx, starty);
    cout << dist[endx][endy] << "\n";

    return 0;
}