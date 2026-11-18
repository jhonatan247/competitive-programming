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
    int n;
    cin >> n;
    
    vector<int> a(n);
    F0R(i, n) {
        cin >> a[i];
    }

    vector<int> b(n);
    F0R(i, n) {
        cin >> b[i];
    }
    
    
    int ans = 0;

    F0R(i, n) {
        int A = 1, B = 1;
        if(i) {
            A = gcd(a[i], a[i - 1]);
        }
        if(i < n - 1) {
            B = gcd(a[i], a[i + 1]);
        }

        int op = lcm(A, B);
        debug(a[i], op);

        if(op < a[i]) ans++;
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


