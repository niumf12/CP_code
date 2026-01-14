#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAXN 10000005 
int m[MAXN]; 

signed main() { 
    // freopen("test.inp","r",stdin); 
    // freopen("test.out","w",stdout); 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    int n, k; 
    cin >> n >> k; 
    int x, a, b, c; 
    cin >> x >> a >> b >> c; 
    m[1] = x; 
    for (int i = 2; i <= n; ++i) {  
        m[i] = (a * m[i - 1] + b) % c;
    }

    deque<int> dq; 

    int res = 0; 

    for (int i = 1; i <= n; ++i) { 
        while (dq.size() && m[dq.back()] >= m[i]) dq.pop_back(); 
        dq.push_back(i); 
        if (i >= k) res ^= m[dq.front()]; 
        while (dq.size() && dq.front() <= i - k + 1) dq.pop_front(); 
    }

    cout << res; 

    return 0; 
}