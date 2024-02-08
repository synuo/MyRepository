#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 101;

int dp[MN][MN][MN];

int max(int a, int b, int c) { //인자 3개짜리 최대값 함수
    return max(max(a, b), c);
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3; //3개의 문자열 입력
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            for(int k = 1; k < s3.size(); k++) {
                if(s1[i] == s2[j] && s2[j] == s3[k]) { //3개 문자가 모두 같은 경우
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1; //이전 공통 부분 문자열 크기에 1을 더함
                }
                else { //같지 않은 경우
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]); 
                    //지금까지의 최대값 저장
                }
            }
        }
    }
    cout << dp[s1.size()-1][s2.size()-1][s3.size()-1];
}