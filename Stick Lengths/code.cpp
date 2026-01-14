#include <bits/stdc++.h>
#define int long long 
using namespace std; 

int32_t main() { 
    if (fopen("test.inp","r")) {  
        freopen("test.inp","r",stdin); 
        freopen("test.out","w",stdout); 
    } 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n; cin >> n; 
    int a[n + 2];
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    sort(a + 1, a + 1 + n); 
    int x = a[(1 + n) / 2]; 
    int dapan = 0; 
    for (int i = 1; i <= n; ++i) dapan += abs(a[i] - x); 
    cout << dapan; 
    return 0; 
}