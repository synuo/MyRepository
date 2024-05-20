#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n;
int map[52][52]; // 빈 방, 막힌 방
int visit[52][52]; // 뚫고 온 개수 저장
int dx[] = {0, 0, -1, 1}; // 상하좌우
int dy[] = {1, -1, 0, 0}; // 상하좌우
 
void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = 0; // 시작 점은 0으로 세팅
    while(!q.empty()){
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i]; // 다음 x 좌표
            int ny = y + dy[i]; // 다음 y 좌표
            if(nx >=0 && nx < n && ny>=0 && ny <n){
                if(map[ny][nx] == 1){ // 갈 수 있는 방
                    if(visit[ny][nx] > visit[y][x]){
                        //뚫고 온 방의 개수 비교 
                        visit[ny][nx] = visit[y][x];
                        q.push(make_pair(nx, ny)); // 다음 방으로 이동
                    } 
                }else{ // 비어 있는 방
                    if(visit[ny][nx] > visit[y][x]+1){
                        //뚫고 온 방의 개수 비교
                        visit[ny][nx] = visit[y][x]+1;
                        q.push(make_pair(nx, ny)); // 다음 방으로 이동
                    } 
                }
            }
        }  
    }     
}
 
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    char a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a;
            map[i][j] = a - '0'; // 입력을 int로 바꾸어줌
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visit[i][j] = 987654321; // 최대 값
        }
    }
    bfs();
    cout << visit[n - 1][n - 1] << endl;
 
    return 0;
}
