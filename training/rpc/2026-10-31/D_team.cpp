#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using ld  = long double;
using ull = unsigned long long;

template <typename T>
void print_vector(const vector<T>& vec) {
    for (const T& x : vec) cout << x << '\t';
    cout << '\n';
}


struct SegTree {
    struct Node { ll sum, mn, mx; };
    static constexpr ll INF = 1e18;
    static constexpr Node identity{0, INF, -INF};

    int n, z;
    vector<ll> a;
    vector<Node> t;

    static Node merge(const Node& L, const Node& R) {
        return {L.sum + R.sum,
                min(L.mn, L.sum + R.mn),
                max(L.mx, L.sum + R.mx)};
    }

    void build(int v, int l, int r) {
        if (l == r) { t[v] = {a[l], a[l], a[l]}; return; }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, ll val) {
        if (l == r) { t[v] = {val, val, val}; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else          update(2 * v + 1, m + 1, r, pos, val);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    Node query(int v, int l, int r, int ql, int qr) const {
        if (qr < l || r < ql) return identity;
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) / 2;
        return merge(query(2 * v, l, m, ql, qr),
                     query(2 * v + 1, m + 1, r, ql, qr));
    }

    SegTree(const vector<ll>& arr, const int zero_idx)
        : n(arr.size()), z(-1), a(arr), t(4 * max<size_t>(1, arr.size())) {
        z = zero_idx;
        if (n > 0) build(1, 0, n - 1);
    }

    bool exists_subarray() const {
        bool hasA = (z >= 1), hasB = (z <= n - 2);

        ll c = hasA ? query(1, 0, n - 1, 0, z - 1).sum : 0;

        ll aLo = 0, aHi = 0, bLo = 0, bHi = 0;
        if (hasA) {
            Node q = query(1, 0, n - 1, 0, z - 2);
            aLo = min<ll>(0, q.mn);
            aHi = max<ll>(0, q.mx);
        }
        if (hasB) {
            Node q = query(1, 0, n - 1, z + 1, n - 1);
            bLo = c + q.mn;
            bHi = c + q.mx;
        }

        return (hasA && aLo <= c && c <= aHi)
            || (hasB && bLo <= c && c <= bHi)
            || (hasA && hasB && max(aLo, bLo) <= min(aHi, bHi));
    }

    void move(int j) {
        a[z] = 1; update(1, 0, n - 1, z, 1);
        a[j] = 0; update(1, 0, n - 1, j, 0);
        z = j;
    }
};


int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);

    int n; cin >> n;
    vector<ll> a(n);
    vector<int> idx(n);
    vector<bool> ans(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(),idx.end(),[&](int i, int j) {return a[i] >= a[j];});
    for (int i = 0; i < n; i++) a[i] = -1;
    a[idx[0]] = 0;
    SegTree sg(a,idx[0]);
    for (int i = 0; i < n; i++) {
        ans[idx[i]] = sg.exists_subarray();
        if (i < n - 1) sg.move(idx[i + 1]);
    }
    for (bool exists : ans) {
        cout << (exists ? "YES " : "NO ");
    }
    cout << '\n';
    return 0;
}