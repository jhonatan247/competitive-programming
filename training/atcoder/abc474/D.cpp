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

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n;
    cin >> n;
    
    vector<_ll> A(n);
    F0R(i, n) {
        cin >> A[i];
    }
    vector<_ll> B(n);
    F0R(i, n) {
        cin >> B[i];
    }
    
    bool exists = false;
    F0R(i, n) {
        if(A[i] > B[i]) {
            exists = true;
            break;
        }
    }

    if(!exists) {
        cout << "No" << nl;
        return;
    }
    
    cout << "Yes" << nl;
    _ll opt = 1e18l;
    F0R(i, n) {
        if(A[i] > B[i]) {
            cout << opt << nl;
        } else {
            cout << 1 << nl;
        }
    }
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


