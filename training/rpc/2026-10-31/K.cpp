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
    int n, m, t;
    cin >> n >> m >> t;
    debug(n, m, t); 
    while(m--) {
        int p, s, l;
        char d;
        cin >> p >> s >> d >> l;
        
        int newp = p + (d == 'L' ? (-t * s) : (t * s));
        int newh = d == 'L' ? newp : (newp + l - 1);
        debug(newp, newh);
        F0R(i, n) {
            if(i == newh) {
                cout << '!';
                continue;
            }
            if(i >= newp and i <= newp + l - 1) {
                cout << "#";
                continue;
            } 
            cout << "=";
        }
        cout << nl;
    }

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


