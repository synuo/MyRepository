#include <iostream>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

ll ternary_search(ll n, ll c) {
	if (n == 0) return 0;

	ll l = 0, r = c / n;

	while (r - l > 3) {
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;

		ll p1 = m1 * (c - m1 * n);
		ll p2 = m2 * (c - m2 * n);

		if (p1 > p2) r = m2;
		else l = m1;
	}

	ll ans = l;
	ll profit = ans * (c - ans * n);

	for (ll i = l + 1; i <= r; i++) {
		ll tmp = i * (c - i * n);
		
		if (tmp > profit) {
			profit = tmp;
			ans = i;
		}
	}

	return ans;
}


int main() {

	FASTIO;
	ll n, c;

	while (cin >> n >> c) {
		cout << ternary_search(n, c) << "\n";
	}

	return 0;
}