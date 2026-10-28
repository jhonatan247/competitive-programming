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

int findFirst(_vi &arr, int v) { 
    int l = 0;
    int r = sz(arr) - 1;

    while(l < r) {
        int md = (r - l) / 2 + l;
        if(arr[md] == v) {
            return v;
        }
        if(arr[md] > v) {
            r = md;
        } else {
            l = md + 1;
        }
    }

    return arr[r];
}

void solve() {
    int q;
    cin >> q;
    string s, t;
    cin >> s >> t;
    
    _vi subst;

    F0R(i, sz(s)) {
        if(i + sz(t) > sz(s)) break;
        bool subs = true;
        F0R(j, sz(t)) {
            if(s[i + j] != t[j]) {
                subs = false;
                break;
            }
        }
        if(subs) {
            subst.pb(i + 1); 
        }
    }

    debug(subst);

    F0R(i, q) {
        int l, r;
        cin >> l >> r;
        if(!sz(subst)) {
            cout << "No" << nl;
            continue;
        }
        int sub = findFirst(subst, l);
        debug(l, r, sub);
        if(l <= sub and sub + sz(t) - 1 <= r) {
            cout << "Yes" << nl;
        } else {
            cout << "No" << nl;
        }
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


