#include <bits/stdc++.h>
bool M1;
#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REV(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
using namespace std;


///++++++++++++++++++++++++++++++++++++++///

void solve() {
    int n, q; cin >> n >> q; 
    int a[n + 2]; 
    for (int i = 0; i <= n + 1; i++) a[i] = 0; 
    for (int Nium = 1; Nium <= q; Nium++) { 
        int l, r; cin >> l >> r; 
        a[l]++; 
        a[r + 1]--; 
    }
    for (int i = 1; i <= n; i++) a[i] += a[i - 1]; 
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; 
}   

///++++++++++++++++++++++++++++++++++++++///

#define task "test"
int32_t main() {
    // if (fopen(task".inp","r")) {
    //     freopen(task".inp","r",stdin);
    //     freopen(task".out","w",stdout);
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    bool M2;
    cerr << "++++++++++++++++++++++++++++\n";
    cerr << "Time: " << clock() << "ms" << '\n';
    cerr << "Memory: " << abs(&M2 - &M1) / 1024 / 1024 << "MB" << '\n';
    cerr << "++++++++++++++++++++++++++++\n";
    return 0;
}
