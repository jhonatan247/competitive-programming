#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "local/debug.h"
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long _ll;
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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n, q;
    cin >> n >> q;
    
    _vl a(n + 1);
    FOR(i, 1, n + 1) {
        cin >> a[i];
    }
    
    _vl b(n + 1);
    FOR(i, 1, n + 1) {
        cin >> b[i];
    }
    
    _vl psum(n + 1);
    psum[0] = 0;
    FOR(i, 1, n + 1) {
        psum[i] = psum[i - 1] +  a[i];
    }

    _vl D(n + 2, LLONG_MAX);
    D[n + 1] = 0;

    _vb visited(n + 1, false);
    pqg<pair<_ll, int>> dks;
    
    FOR(i, 1, n + 1) {
        dks.push(mp(b[i], i));
    }

    while(sz(dks)) {
        auto curr = dks.top();
        int id = curr.sc;
        assert(id >= 1 and id <= n);
        dks.pop();
        
        if(visited[id]) continue;

        visited[id] = true;

        D[id] = curr.fr;

        int nextr = (id % n) + 1;
        int nextl = ((id - 2) % n  + n) % n  + 1;
        assert(nextr >= 1 and nextr <= n);
        assert(nextl >= 1 and nextr <= n);

        if(!visited[nextr]) {
            dks.push(mp(curr.fr + a[id], nextr));    
        }
        if(!visited[nextl]) {
            dks.push(mp(curr.fr + a[nextl], nextl));    
        }
    }

    debug(psum);
    debug(D);

    F0R(i, q) {
        int s, t;
        cin >> s >> t;
        if(s == n + 1 or t == n + 1) {
            cout << max(D[s], D[t]) << nl;
            continue;
        }
        if(s > t) swap(s, t);
        debug(s, t);

        _ll x = psum[t - 1] - psum[s - 1];
        
        debug(D[s] + D[t], psum[n] - x, x);

        _ll dst = min({D[s] + D[t], psum[n] - x, x});
        cout << dst << nl;
    }


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


