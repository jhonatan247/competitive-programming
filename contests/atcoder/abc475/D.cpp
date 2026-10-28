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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
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
const int MX = 1e7 + 1;

_vs P;

void cribe(int tsz) {
    _vb isPrime(MX, true);
    P.clear();

    FOR(i, 2, MX) {
        if(!isPrime[i]) {
            continue;
        }
        int psz = 0;
        int curr = i;
        while(curr) {
            curr /= 10;
            psz++;
        }
        if(psz == tsz) {
            P.pb(to_string(i));
        } else if(psz > tsz) break;

        for(_ll j = i * (_ll)i; j < MX; j += i) {
            isPrime[j] = false;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    
    cribe(sz(s));
    
    F0R(i, sz(P)) {
        F0R(j, sz(s) - 1) {
            FOR(k, j + 1, sz(s)) {
                if(s[j] == s[k] and P[i][j] != P[i][k])
                    goto invalid;
                if(s[j] != s[k] and P[i][j] == P[i][k])
                    goto invalid;
            }
        }
        cout << P[i] << nl;
        return;
        
        invalid:
            continue;
    }
    cout << -1 << nl;
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


