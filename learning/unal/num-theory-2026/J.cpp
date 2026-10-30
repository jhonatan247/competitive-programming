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

template<typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> ans;
    ans.pb(1);

    _ll prod = 1;

    for(int i = 2; i < n; i++) {
        if(gcd(i, n) == 1) {
            ans.pb(i);
            prod = (prod * i) % n;
        }       
    }

    if(prod == n - 1 and n > 2) {
        ans.pop_back();
    }

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
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


