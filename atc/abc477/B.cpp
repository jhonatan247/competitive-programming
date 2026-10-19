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

void solve() {
    int n, d;
    cin >> n >> d;
    
    vector<_pi> arr(n);
    F0R (i, n) {
        int x;
        cin >> x;
        arr[i] = mp(x, i + 1);
    }

    sort(all(arr));
    _vi ans;

    F0R(i, n) {
        auto curr = arr[i];
        if(i == 0 and arr[i + 1].fr - curr.fr >= d) {
            ans.pb(curr.sc);
        }
        if(i == n - 1 and curr.fr - arr[i - 1].fr >= d) {
            ans.pb(curr.sc);
        }
        if(i and i < n - 1 and arr[i + 1].fr - curr.fr >= d and curr.fr - arr[i - 1].fr >= d) {
            ans.pb(curr.sc);
        } 
    }

    sort(all(ans));

    cout << sz(ans) << nl;

    F0R(i, sz(ans)) {
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << nl;
    
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


