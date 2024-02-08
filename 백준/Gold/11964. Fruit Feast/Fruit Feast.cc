#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int val;
	bool half;
};
info tmp;
bool check[5000001] = { false, };
vector<int> v;

int main() {
	int t, a, b, result;
	cin >> t >> a >> b;
	result = a;
	queue<info> q;
	tmp.half = false;
	tmp.val = a;
	check[a] = true;
	q.push(tmp);
	v.push_back(a);
	if (!check[b]) {
		tmp.val = b;
		check[b] = true;
		q.push(tmp);
		result = max(result, b);
		v.push_back(b);
	}

	while (!q.empty()) {
		int cv = q.front().val;
		bool ch = q.front().half;
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			int nv = v[i] + cv;
			if (nv <= t && !check[nv]) {
				result = max(result, nv);
				check[nv] = true;
				tmp.half = ch;
				tmp.val = nv;
				q.push(tmp);
			}
			if (!ch) {
				nv = cv / 2 + v[i];
				if (nv <= t && !check[nv]) {
					result = max(result, nv);
					check[nv] = true;
					tmp.half = true;
					tmp.val = nv;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	return 0;
}