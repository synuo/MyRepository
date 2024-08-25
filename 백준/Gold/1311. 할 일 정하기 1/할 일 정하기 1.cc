#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;

int N;
int D[21][21]; //D[i][j] : i번 사람이 j번 일을 할 때 필요한 비용
int v[21][1 << 20];

int dp(int work, int state) { 
	//사람들의 상태가 state일 때 work부터 마지막 일까지 수행하는 최소비용
	if (work == N) return 0;

	int& ret = v[work][state];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i < N; i++) {
		if ((state & (1 << i)) != 0) continue;
		ret = min(ret, D[i][work] + dp(work + 1, state | (1 << i)));
	}

	return ret;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(v, -1, sizeof(v));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> D[i][j];
		}
	}

	cout << dp(0, 0);

	return 0;
}