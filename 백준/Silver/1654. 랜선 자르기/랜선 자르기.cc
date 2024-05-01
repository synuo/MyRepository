#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int cable[10001];

bool solve(long long len) {
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += cable[i] / len;
	}

	return sum >= n;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> cable[i];
	sort(cable, cable + k);

	//랜선의 길이가 x일 때 랜선이 n개 이상인지 아닌지
	long long st = 0, en = cable[k - 1];

	while (st < en) {
		long long mid = (en + st + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st << '\n';

	return 0;
}