#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int MAXN = 1e5 + 5;  
int l[MAXN]; 
int r[MAXN]; 
int a[MAXN]; 

signed main() { 
    freopen("test.inp","r",stdin); 
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, q, m; 
    cin >> n >> q >> m; 

    for (int i = 1; i <= q; ++i) { 
        int ll, rr; 
        cin >> ll >> rr; 
        l[i] = ll; 
        r[i] = rr; 
    }

    for (int Nium = 1; Nium <= m; ++Nium) { 
        int x, y; 
        cin >> x >> y; 
        for (int i = x; i <= y; ++i) { 
            int ll = l[i]; 
            int rr = r[i]; 
            for (int ii = ll; ii <= rr; ++ii) a[ii]++;
        }
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; 

    return 0; 
}