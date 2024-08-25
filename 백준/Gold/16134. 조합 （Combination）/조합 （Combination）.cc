#include <iostream>
#include <cstring>
using namespace std;
const long long MOD = 1000000007;

//(N R)의 값을 1000000007(소수)로 나눈 나머지를 출력하자 
//p가 소수면 모든 정수에 대해 a의 p승을 p로 나눈 나머지는 a를 p로 나눈 나머지와 같다.

long long power(int a, int n) {  //a의 n승 계산
	if (n == 0) return 1;

	long long half = power(a, n / 2);
	if (n % 2 == 0) return half * half % MOD;
	else return (half * half % MOD) * a % MOD;
}

int modularinverse(int n) {   //모듈로 곱셉 역원
	return power(n, MOD - 2);
}

int combination(int n, int r) {  //조합 계산 
	long long ret = 1;

	for (int i = 0; i < r; i++) {
		ret = ret * (n - i) % MOD;
	}
	for (int i = r; i >= 1; i--) {
		ret = ret * modularinverse(i) % MOD;
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, R;
	cin >> N >> R;

	cout << combination(N, R);

	return 0;
}