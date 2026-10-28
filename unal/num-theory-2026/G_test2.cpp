#ifdef LOCAL
    #define _GLIBCXX_DEBUG
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

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ll MX = 1001;

int LP[MX];
vector<int> P;

void linear_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (LP[i] == 0) {
            LP[i] = i;
            P.push_back(i);
        }
        for (int p : P) {
            if (p > LP[i] || i * p > n) break;
            LP[i * p] = p;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    map<int, int> groups;

    _vi ans(n);

    F0R(i, n) {
        auto least_prime = LP[arr[i]];
        if(groups.count(least_prime)) {
            ans[i] = groups[least_prime];
        } else {
            groups[least_prime] = sz(groups) + 1;
            ans[i] = sz(groups);
        }
    }
    
    cout << sz(groups) << nl;
    F0R(i, n) {
        if(i) cout << ' ';
        cout << ans[i];
    }

    cout << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    linear_sieve(MX);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


