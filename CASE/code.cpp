#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() { 
    int n; cin >> n; 
    int lo = 1, hi = 1e9 + 5, ans = hi; 
    while (lo <= hi) { 
        int mid = (lo + hi) >> 1; 
        if (mid * (mid + 1) / 2 >= n) { 
            ans = mid; 
            hi = mid - 1; 
        } else lo = mid + 1; 
    }
    int vitri = n - ans * (ans - 1) / 2; 
    cout << ans << ' ' << vitri << '\n'; 
}

int32_t main() { 
    freopen("test.inp","r",stdin); 
    freopen("test.out","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve(); 
    return 0; 
}