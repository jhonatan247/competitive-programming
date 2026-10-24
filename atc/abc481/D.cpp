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

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvb> _vvvb;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define fill0(a) memset(a, 0, sizeof a)
#define fill(a, v) memset(a, v, sizeof a)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    _vvi adj(n + 1);
    _vpi min(n + 1, mp(INT_MAX, -1));

    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        if(b < min[a].fr) {
            min[a] = mp(b, sz(adj[a]));
        }
        adj[a].pb(b);
    }

    FOR(i, 1, n + 1) {
        if(!sz(adj[i])) continue;

        swap(adj[i][0], adj[i][min[i].sc]);
    }

    pqg<_pi> dks;
    dks.push(mp(0, s));
    
    _vi dst(n + 1, INT_MAX);
    dst[s] = 0;


    while(sz(dks)) {
        auto curr = dks.top();
        dks.pop();
        
        if(curr.fr < dst[curr.sc]) continue;

        if(curr.sc == t) {
            cout << curr.fr << nl;
            return;
        } 

        bool smallest = true;
        TRAV(child, adj[curr.sc]) {
            int cost = 1;
            if(smallest) {
                cost = 0;
                smallest = false;
            }
            if(curr.fr + cost < dst[child]) {
                dst[child] = curr.fr + cost;
                dks.push(mp(curr.fr + cost,child));
            }
        }
    }
    cout << -1 << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    #warning "LOCAL ONLY: reading T for multi-test"
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


