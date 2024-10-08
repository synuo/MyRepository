#include <iostream>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;

ll n, y[300001], d[300001];

ll f(ll h) {
    ll sum = 0;
    for(int i=1; i<=n; i++)
        sum += abs(y[i] - (h + abs(n / 2 + 1 - i))) + abs(d[i] - (h + abs(n / 2 + 1 - i)));
    return sum;
}

int main() {
    
    FASTIO;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> y[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    
    ll lo=0, hi=1e12+1, h;
    while (lo < hi - 1) {
        h = (lo + hi) / 2;
        if (f(h) - f(h - 1) <= 0) lo = h;
        else hi = h;
    }
    
    cout << f(lo) << '\n';
    
    return 0;
}