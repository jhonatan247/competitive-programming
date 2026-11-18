#ifdef LOCAL
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
    string P, S;
    cin >> P >> S;
    
    int i = 0;
    int j = 0;
    while(i < sz(P) and j < sz(S)) {
        char curr = P[i];
        int cnt = 0;
        while(i < sz(P) and P[i] == curr) {
            i++;
            cnt++;
        }
        int scnt = 0;
        while(j < sz(S) and S[j] == curr) {
            j++;
            scnt++;
        }
        if(scnt < cnt or scnt > 2 * cnt) {
            goto NO;
        }
    }

    if(i != sz(P) or j != sz(S)) {
        goto NO;
    }

    cout << "YES" << nl;
    return;

    NO:
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


