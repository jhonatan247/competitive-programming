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
    int n;
    cin >> n;
    
    _vi divisors;
    for(_ll i = 2; i * i<= n; i++) {
        if(n % i == 0) {
            divisors.pb(i);
            if(i * i != n) {
                divisors.pb(n / i);
            }
        }
    }
    sort(all(divisors));

    int curr = n;
    _vi ans;

    F0R(i, sz(divisors)) {
        if(curr % divisors[i] == 0) {
            curr /= divisors[i];
            ans.pb(divisors[i]);
        }
        if(sz(ans) == 2) break;
    }

    if(sz(ans) == 2 and curr != 1 and curr != ans[0] and curr != ans[1]) {
        cout << "YES" << nl;
        cout << ans[0] << ' ' << ans[1] << ' ' << curr << nl;
        return;
    }
    cout << "NO" << nl;
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


