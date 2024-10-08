#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 4000
typedef long long ll;

int N;
ll Answer;
vector<int> AB, CD;
int Arr[4][MAX];

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> Arr[j][i];
        }
    }
}

void Solution() {
    // AB, CD 배열에 모든 경우의 수를 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(Arr[0][i] + Arr[1][j]);
            CD.push_back(Arr[2][i] + Arr[3][j]);
        }
    }
    
    // AB와 CD를 각각 정렬
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    // 투 포인터로 합이 0인 쌍을 찾기
    int ab_idx = 0, cd_idx = CD.size() - 1;
    while (ab_idx < AB.size() && cd_idx >= 0) {
        int sum = AB[ab_idx] + CD[cd_idx];

        if (sum == 0) {
            ll ab_count = 0, cd_count = 0;
            int ab_val = AB[ab_idx];
            int cd_val = CD[cd_idx];

            // AB에서 같은 값의 수 세기
            while (ab_idx < AB.size() && AB[ab_idx] == ab_val) {
                ab_count++;
                ab_idx++;
            }

            // CD에서 같은 값의 수 세기
            while (cd_idx >= 0 && CD[cd_idx] == cd_val) {
                cd_count++;
                cd_idx--;
            }

            // 쌍의 개수 더하기
            Answer += ab_count * cd_count;
        }
        else if (sum < 0) {
            ab_idx++; // AB의 값을 증가시켜 더 큰 합을 만들기
        }
        else {
            cd_idx--; // CD의 값을 감소시켜 더 작은 합을 만들기
        }
    }

    // 결과 출력
    cout << Answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solution();

    return 0;
}
