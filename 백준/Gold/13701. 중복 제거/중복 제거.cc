#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    bitset <33554432> B;
    for (int i; cin >> i;)
        if (!B[i])
            B[i] = 1, cout << i << ' ';
}
