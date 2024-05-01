#include <iostream>
#include <algorithm>
using namespace std;

long long int M, N; //조카의 수, 과자의 수
long long int a[1000001];

bool solve(long long len) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i] / len;
	}

	return sum >= M;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {  //과자 N개의 길이 
		cin >> a[i];
	}
	sort(a, a + N);

	//과자의 길이가 x일 때 과자가 M개 이상인가 아닌가
	long long st = 0, en = a[N - 1];

	while (st < en) {
		long long mid = (en + st + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st << '\n';

	return 0;
}