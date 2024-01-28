#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    queue <int> Q;
    int minsec[100001] = { 0, };  
    int nowN;

    cin >> N >> K;
    Q.push(N);

    while (!Q.empty()) {
        nowN = Q.front();
        Q.pop();

        if (nowN < 0 || nowN>100000) continue;

        if (nowN == K) {
            cout << minsec[nowN];
            break;
        }
        //뒤로 한칸
        if (nowN - 1 >= 0 && minsec[nowN - 1] == 0) {
            minsec[nowN - 1] = minsec[nowN] + 1;
            Q.push(nowN - 1);
        }
        //앞으로 한칸
        if (nowN + 1 <= 100000 && minsec[nowN + 1] == 0) {
            minsec[nowN + 1] = minsec[nowN] + 1;
            Q.push(nowN + 1);
        }
        //순간이동
        if (2*nowN <= 100000 && minsec[2*nowN] == 0) {
            minsec[2 * nowN] = minsec[nowN] + 1;
            Q.push(2 * nowN);
        }
    }

    return 0;
}