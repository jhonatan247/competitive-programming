#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include "algo/bit.h"

using namespace std;
using namespace bit;

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

void solve() {
    int n;
    cin >> n;
    
    int min_a = INT_MAX;
    int max_a = INT_MIN;
    F0R(i, n) {
        int a;
        cin >> a;
        min_a = min(min_a, a);
        max_a = max(max_a, a);
    }

    int max_bit = highest_set_bit_index(max_a);

    int ans = 0;
    bool diff = false;
    int curr_pow = 1 << max_bit;

    while(curr_pow) {
        if((max_a & curr_pow) != (min_a & curr_pow)) {
            diff = true;
        }

        if(diff or (max_a & curr_pow)) {
            ans |= curr_pow;
        }
        curr_pow >>= 1;
    }

    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


