#ifdef LOCAL
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef int64_t _ll;
typedef long double _ld;
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<bool> _vb;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)
#define P_TRAV(k, a, x) for (auto& [k, a] : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const _ll MOD1 = 1000000007LL;
const _ll MOD2 = 1000000009LL;

_ll mod_pow(_ll base, _ll exp, _ll mod) {
    _ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

_ll mod_inv(_ll a, _ll mod) {
    return mod_pow(a, mod - 2, mod);
}

// Maintains a linear basis with timestamps (rightmost occurrence of each pivot)
struct LinearBasis {
    int dim;
    _ll mod;
    _vvl basis;
    _vi ts;

    LinearBasis(int d, _ll m) : dim(d), mod(m), basis(d, _vl(d, 0)), ts(d, -1) {}

    void normalize(_vl& vec, int pivot) {
        _ll inv = mod_inv(vec[pivot], mod);
        FOR(c, pivot, dim) {
            vec[c] = (vec[c] * inv) % mod;
        }
    }

    // Inserts vector at index `idx`.
    // Returns -1 if linearly independent; otherwise returns the maximum left endpoint `i <= idx`
    // such that vectors in [i, idx] are linearly dependent.
    int add(_vl vec, int idx) {
        F0R(d, dim) {
            if (vec[d] == 0) continue;

            if (ts[d] == -1) {
                normalize(vec, d);
                basis[d] = vec;
                ts[d] = idx;
                return -1;
            }

            // Greedily keep the fresher vector in the basis so timestamps stay maximized
            if (idx > ts[d]) {
                normalize(vec, d);
                swap(vec, basis[d]);
                swap(idx, ts[d]);
            }

            _ll factor = mod - vec[d];
            FOR(c, d, dim) {
                vec[c] = (vec[c] + factor * basis[d][c]) % mod;
            }
        }
        return idx;
    }
};

// Reads one cable type and builds its net-flow vector of size (n - 1)
_vl read_cable_type(int n) {
    int m;
    cin >> m;
    _vl flow(n, 0);
    F0R(e, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        flow[u]--; // Outgoing data
        flow[v]++; // Incoming data
    }
    flow.pop_back(); // Last coordinate is redundant since total net flow is always 0
    return flow;
}

_vl to_mod_vec(const _vl& raw, _ll mod) {
    _vl res(sz(raw));
    F0R(i, sz(raw)) {
        res[i] = ((raw[i] % mod) + mod) % mod;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int dim = n - 1;
    LinearBasis lb1(dim, MOD1), lb2(dim, MOD2);

    int min_len = k + 1;

    F0R(j, k) {
        _vl raw_flow = read_cable_type(n);

        int left1 = lb1.add(to_mod_vec(raw_flow, MOD1), j);
        int left2 = lb2.add(to_mod_vec(raw_flow, MOD2), j);

        // Dependent over R iff dependent under both primes
        int left_idx = min(left1, left2);
        if (left_idx != -1) {
            min_len = min(min_len, (int)j - left_idx + 1);
        }
    }

    if (min_len > k) {
        cout << -1 << nl;
    } else {
        cout << min_len << nl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}
