#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[100005];

int binarysearch(int target) {
	int st = 0;
	int en = N - 1;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (target < a[mid])
			en = mid - 1;
		else if (target > a[mid])
			st = mid + 1;
		else
			return 1;
	}

	return 0;


}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int t; cin >> t;
		cout << binarysearch(t) << "\n";
	}

	return 0;
}