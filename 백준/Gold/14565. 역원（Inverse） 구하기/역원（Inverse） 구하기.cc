#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std; 
typedef long long ll;

//ax + by = gcd(a, b)
struct Result {
	ll x;
	ll y;
	ll g;
};

Result extended_gcd(ll a, ll b) {
	//gcd(a, 0) = a
	//ax + 0y = a 따라서 x = 1, y = 0
	if (b == 0)  return { 1, 0, a };

	//bx' + ry' = g
	//res = {x', y', g}
	Result res = extended_gcd(b, a%b);

	//ax + by = bx' + ry'
	//x = y', y = x' - (a/b * y')
	return { res.y, res.x - (a / b * res.y), res.g };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, A;
	cin >> N >> A;

	//덧셈역 
	//(A+x) mod N = 0
	// A + x = N
	cout << N - A << " ";

	//곱셈역
	//(Ax) mod N = 1
	//Ax + Ny = 1 = gcd(A, N)
	Result res = extended_gcd(A, N);

	if (res.g != 1 || res.x == 0) cout << "-1";
	else {
		while (res.x < 0) res.x += N;
		cout << res.x;
	}

	return 0;
}