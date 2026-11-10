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
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ll MX = 200001;

int dp[MX], a[MX];
deque<int> q[MX];

void solve() {
    int n;
    cin >> n;

    n++;
    
    FOR(i, 1, n) {
        cin >> a[i];
        q[i].clear();
    }

    FOR(i, 1, n) {
        dp[i] = dp[i - 1];
        deque<int> &prev = q[a[i]];

        prev.emplace_back(i);

        if(sz(prev) > a[i]) {
            prev.pop_front();
        }

        if(sz(prev) == a[i]) {
            dp[i] = max(dp[i], dp[prev.front() - 1] + a[i]);
        }
    }

    cout << dp[n - 1] << nl;
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


