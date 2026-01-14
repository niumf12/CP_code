#include <bits/stdc++.h>
#define int long long 
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i) 
#define REV(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
using namespace std;

#define MAXN 100005 
int n, m; 
int a[MAXN]; 

int sum1n(int n) { 
    return n * (n + 1) / 2; 
}

int sumlr(int l, int r) { 
    return sum1n(r) - sum1n(l - 1); 
}

struct node { 
    int fixed;
    int sum; 
    int d_val;  
    node(int _fixed = 0, int _sum = 0, int _d_val = 0) { 
        fixed = _fixed; 
        sum = _sum; 
        d_val = _d_val; 
    }
};

node combine(const node &a, const node &b) { 
    node res = node(); 
    res.fixed = a.fixed + b.fixed; 
    res.sum = a.sum + b.sum; 
    return res; 
}

struct SMT { 
    int n; 
    vector<node> st;
    SMT(int _n = 0) { 
        n = _n; 
        st.assign((n << 2) + 5, node()); 
    }

    void upd_fix(int id, int l, int r, int p, int val) { 
        if (p < l || r < p) return; 
        if (l == r) { 
            st[id].fixed += val; 
            st[id].sum += val * l; 
            return; 
        }
        int mid = (l + r) >> 1; 
        upd_fix(id << 1, l, mid, p, val); 
        upd_fix(id << 1 | 1, mid + 1, r, p, val); 
        st[id] = combine(st[id << 1], st[id << 1 | 1]); 
    }
    void upd_fix(int p, int val) { 
        upd_fix(1, 1, n, p, val); 
    }
    
    void pushDown(int id, int l, int r, int mid) { 
        if (st[id].d_val == 0) return; 
        node &ll = st[id << 1]; 
        node &rr = st[id << 1 | 1];  
        node &mm = st[id];
        ll.sum += sumlr(l, mid) * mm.d_val; 
        rr.sum += sumlr(mid + 1, r) * mm.d_val; 
        ll.fixed += (mid - l + 1) * mm.d_val; 
        rr.fixed += (r - mid) * mm.d_val; 
        ll.d_val += mm.d_val; 
        rr.d_val += mm.d_val; 
        mm.d_val = 0; 
    }

    void upd(int id, int l, int r, int u, int v, int val) { 
        if (v < l || r < u) return; 
        if (u <= l && r <= v) { 
            st[id].sum += sumlr(l, r) * val; 
            st[id].fixed += val * (r - l + 1); 
            st[id].d_val += val; 
            return;
        }
        int mid = (l + r) >> 1; 
        pushDown(id, l, r, mid); 
        upd(id << 1, l, mid, u, v, val); 
        upd(id << 1 | 1, mid + 1, r, u, v, val); 
        st[id] = combine(st[id << 1], st[id << 1 | 1]); 
    }
    void upd(int u, int v, int val) { 
        upd(1, 1, n, u, v, val); 
    }

    node get(int id, int l, int r, int u, int v) { 
        if (v < l || r < u) return node(); 
        if (u <= l && r <= v) return st[id]; 
        int mid = (l + r) >> 1; 
        pushDown(id, l, r, mid);
        return combine(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v)); 
    }
    int get(int u, int v) { 
        node tmp = get(1, 1, n, u, v); 
        return -(u - 1) * tmp.fixed + tmp.sum; 
    }
} tree; 

void solve() { 
    cin >> n >> m; 
    FOR(i, 1, n) cin >> a[i]; 
    tree = SMT(n); 
    FOR(i, 1, n) { 
        tree.upd_fix(i, a[i]); 
    }
    FOR(i, 1, m) { 
        int type, l, r, d; 
        cin >> type >> l >> r; 
        if (type == 1) { 
            cin >> d; 
            tree.upd(l, r, d); 
        } else { 
            cout << tree.get(l, r) << '\n'; 
        }
    }
}

int32_t main() { 
    freopen("test.inp","r",stdin); 
    freopen("test.out","w",stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); 
    solve(); 
    return 0; 
}