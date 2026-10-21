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

#define _fr(x) get<0>(x)
#define _sc(x) get<1>(x)
#define _th(x) get<2>(x)
#define mt(...) make_tuple(__VA_ARGS__)

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n, q;
    cin >> n >> q;
    n++;

    vector<_ll> A(n);
    FOR (i, 1, n) {
        cin >> A[i];
    }
    
    vector<_ll> B(n);
    FOR (i, 1, n) {
        cin >> B[i];
    }

    vector<map<int, _ll>> dist(n + 1);

    F0R(i, q) {
        int s, t;
        cin >> s >> t;
        
        pqg<tuple<_ll, _ll, int>> dks;

        dks.push(mt(0, 0, s));
        
        set<int> visited;
        visited.ins(s);

        vector<tuple<_ll, _ll, int>> cvisited;

        while(sz(dks)) {
            debug(dks);
            debug(dist);
            auto curr = dks.top();
            dks.pop();
            
            
            _ll cdist = _fr(curr);
            _ll rdist = _sc(curr);
            _ll id = _th(curr);
            
            if(sz(cvisited)) {
                dist[_th(cvisited.back())][id] = rdist;
                dist[id][_th(cvisited.back())] = rdist;
            }
            dist[s][id] = cdist;
            dist[id][s] = cdist;

            cvisited.pb(curr); 

            if(id == t or dist[id].count(t)) {
                _ll ndist = id == t ? 0 : dist[id][t];
                while(sz(cvisited)) {
                    auto pvisited = cvisited.back();
                    cvisited.pop_back();
                    dist[_th(pvisited)][t] = ndist;
                    dist[t][_th(pvisited)] = ndist;
                    ndist += _sc(pvisited);
                }
                break;
            }

            if(id == n) {
                FOR(next, 1, n) {
                    if(!visited.count(next)) {
                        dks.push(mt(cdist + B[next], B[next], next));
                        visited.ins(next);
                    }
                }
                
            } else {
                int nextidA = id % (n - 1) + 1;
                if(!visited.count(nextidA)) {
                    dks.push(mt(cdist + A[id], A[id], nextidA));
                    visited.ins(nextidA);
                }
                int nextidB = n;
                if(!visited.count(nextidB)) {
                    dks.push(mt(cdist + B[id], B[id], nextidB));
                    visited.ins(nextidB);
                }
                int nextidC = ((id - 2 + (n - 1)) % (n - 1) + 1) % (n - 1);
                if(!visited.count(nextidC)) {
                    dks.push(mt(cdist + A[nextidC], A[nextidC], nextidC));
                    visited.ins(nextidC);
                }
            }
        }
        debug(dist);

        cout << dist[s][t] << nl;

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


