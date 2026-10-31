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

const char nl = '\n';

void solve() {
    int n = 5;
    vector<string> s(n);
    F0R(i, n) {
        cin >> s[i];
    }
    
    int ans = 0;

    F0R(i, n) {
        int curr = 0;
        F0R(j, n) {
            if(s[i][j] == 'o') curr++;
        }
        ans = max(ans, curr);
    }

    F0R(i, n) {
        int curr = 0;
        F0R(j, n) {
            if(s[j][i] == 'o') curr++;
        }
        ans = max(ans, curr);
    }

    int curr = 0;
    F0R(i, n) {
        if(s[i][i] == 'o') curr++;
    }
    ans = max(ans, curr);
    curr = 0;
    F0R(i, n) {
        if(s[i][n - i - 1] == 'o') curr++; 
    }
    ans = max(ans, curr);
    cout << n - ans << nl;
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


