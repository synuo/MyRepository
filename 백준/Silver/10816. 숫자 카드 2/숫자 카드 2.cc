#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[500001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		if (binary_search(arr, arr + N, x) == 1)
			cout << upper_bound(arr, arr + N, x) - lower_bound(arr, arr + N, x) << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}