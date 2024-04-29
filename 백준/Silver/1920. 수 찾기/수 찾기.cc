#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int BinarySearch(int arr[], int size, int target);
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
		// cout << binary_search(arr, arr + N, x) << "\n";
		cout << BinarySearch(arr, N, x) << "\n";
	}

	return 0;
}
int BinarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (target < arr[mid])
			right = mid - 1;
		else if (target > arr[mid])
			left = mid + 1;
		else
			return 1;
	}

	return 0;
}
