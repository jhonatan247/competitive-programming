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
    
    vector<_ll> A(n);
    F0R(i, n) {
        cin >> A[i];
    }
    
    _ll sumEven = 0;
    vector<_ll> odd;
    F0R(i, n) {
        if(A[i] % 2) {
            odd.pb(A[i]);
        } else {
            sumEven += A[i];
        }
    }

    sort(all(odd), greater<_ll>());

    if(!sz(odd)) {
        cout << 0 << nl;
        return;
    }
    
    _ll ans = sumEven;

    F0R(i, (sz(odd) + 1) / 2) {
        ans += odd[i];
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


