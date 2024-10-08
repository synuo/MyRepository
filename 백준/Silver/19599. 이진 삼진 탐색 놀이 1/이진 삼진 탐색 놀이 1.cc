#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);

int binary_search(int x, int l, int r) {
	int cnt = 0;

	while (l <= r) {
		int m = (l + r) / 2;

		if (x == m) break;
		else if (x < m) r = m - 1;
		else l = m + 1;

		cnt++;
	}

	return cnt;
}

int ternary_search(int x, int l, int r) {
	int cnt = 0;

	while (l <= r) {
		int p1 = l + (r - l) / 3;  // 구간을 올바르게 3등분
		int p2 = r - (r - l) / 3;  // 구간을 올바르게 3등분

		if (x == p1) break;
		else {
			cnt++;
			if (x == p2) break;
			else {
				cnt++;
				if (x < p1) r = p1 - 1;
				else if (x < p2) {
					l = p1 + 1;
					r = p2 - 1;
				}
				else l = p2 + 1;
			}
		}
	}
	return cnt;
}


int main() {

	FASTIO;
	int n, small = 0, big = 0, same = 0;
	cin >> n;

	vector <int> bv, tv;

	for (int i = 0; i < n; i++) {
		bv.push_back(binary_search(i, 0, n - 1));
		tv.push_back(ternary_search(i, 0, n - 1));

		if (bv[i] < tv[i]) small++;
		else if (bv[i] == tv[i]) same++;
		else big++;
	}

	cout << small << "\n" << same << "\n" << big << "\n";

	return 0;
}