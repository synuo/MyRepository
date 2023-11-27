#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//N개의 물건, 각 물건은 무게W와 가치 V
//배낭 무게 최대 K

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, w[101], V[101];
	int arr[101][100001] = {0};  //무게와 가치 저장할 배열
	//arr[a][b] -> a개의 물건을 용량이 b인 배낭에 넣을 때 얻을 수 있는 최대 가치 

	cin >> N >> K;   //물건의 개수와 배낭 최대 무게

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> V[i];
	}

	for (int i = 0; i <= N; i++) {
		arr[i][0] = 0;
	}

	for (int i = 0; i <= K; i++) {
		arr[0][i]= 0;
	}

	for (int i = 1; i <= N; i++) { //물건 1부터 N까지
		for (int j = 1; j <= K; j++) {
			if (w[i] > j) {
				arr[i][j] = arr[i - 1][j];
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - w[i]] + V[i]);
			}
		}
	}

	cout<< arr[N][K];

	return 0;
}