#include <bits/stdc++.h>
#define int long long 
using namespace std;

int dem[200005]; 

int32_t main() { 
    // freopen("test.inp","r",stdin); 
    // freopen("test.out","w",stdout); 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n; cin >> n;
    int a[n + 2];
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    /// nen so 
    vector<int> diff; 
    for (int i = 1; i <= n; i++) diff.push_back(a[i]); 
    sort(diff.begin(), diff.end()); 
    diff.erase(unique(diff.begin(), diff.end()), diff.end()); 
    for (int i = 1; i <= n; i++) { 
        a[i] = lower_bound(diff.begin(), diff.end(), a[i]) - diff.begin() + 1; 
    }
    // for (int i = 1; i <= n; i++) { 
    //     cout << a[i] << " \n"[i == n]; 
    // }
    int dapan = 0; 
    for (int i = 1; i <= n; i++) { 
        if (dem[a[i]] == 0) dapan++; 
        dem[a[i]]++; 
    }
    cout << dapan; 
    return 0;
}