#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    
    int n; cin >> n;

    vector<int> ans(2);
    
    int start = 0, end = n - 1, min = 2000000001;
    int arr[n];

    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr, arr + n);
            
    while(start < end) {
        int sum = arr[start] + arr[end];

        if(abs(sum) < min) {
            ans[0] = arr[start];
            ans[1] = arr[end];
            min = abs(sum);
        }
        
        if(sum < 0) start++;
        else end--;
    }

    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " ";

    return 0;
}