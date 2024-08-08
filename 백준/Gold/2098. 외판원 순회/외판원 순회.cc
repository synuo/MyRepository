#include <iostream>
#include <cstring>
#define MAX 16
#define INF 987654321;
using namespace std;


int N, cost[MAX][MAX], dp[MAX][1 << MAX];

int solve(int curr, int status) {

	if (status == (1 << N) - 1) { //모든 도시를 방문(탐색 완료)했다면 
		if (cost[curr][0] == 0) return INF;   //처음으로 이동불가능하면 
		return cost[curr][0];
	}

	if (dp[curr][status] != -1) {  //이미 탐색했으면 
		return dp[curr][status];
	}
		

	dp[curr][status] = INF;

	for (int i = 0; i < N; i++) {
		
		if (cost[curr][i] == 0) continue;  //길이 없다면
		if ((status & (1 << i)) == (1 << i)) continue;  //이미 방문했다면

		dp[curr][status] = min(dp[curr][status], cost[curr][i] + solve(i, status | (1 << i)));
	}

	return dp[curr][status];

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp)); //dp배열 -1로 초기화

	cout << solve(0,1) << endl;

	return 0;

}
