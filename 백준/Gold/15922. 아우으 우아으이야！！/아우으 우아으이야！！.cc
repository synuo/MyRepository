#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<pair<int, int>> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    int ans = 0;
    int start = arr[0].first, end = arr[0].second;

    for (int i = 1; i < n; i++) {
        int x1 = arr[i].first, x2 = arr[i].second;
        if (end > x1) {
            end = max(end, x2);
        }
        else {
            ans += end - start;
            start = x1, end = x2;
        }
    }

    ans += end - start;
    cout << ans;

    return 0;
}