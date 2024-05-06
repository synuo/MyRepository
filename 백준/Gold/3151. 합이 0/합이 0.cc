#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(),v.end()); // 오름차순 정렬
    long long ans = 0; // 경우의 수가 int를 넘을 수 있음

    // 이중 반복으로 2개의 값을 고름
    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size(); j++){
            // 구해야할 나머지 1개의 값을 구함
            long long cnt = v[i]+v[j];
            // 개수 찾는 과정
            int idx1 = lower_bound(v.begin()+j+1,v.end(),-cnt)-v.begin();
            int idx2 = upper_bound(v.begin()+j+1,v.end(),-cnt)-v.begin();
            ans += idx2 - idx1; // 구한 개수를 더함
        }
    }
    cout << ans;
}