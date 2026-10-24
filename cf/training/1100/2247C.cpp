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

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    F0R(i, n) {
        cin >> A[i];
    }
    vector<int> B(n);
    F0R(i, n) {
        cin >> B[i];
    }
    
    int d1 = 0;
    int c1 = 0;
    int d0 = 0;
    int c0 = 0;
    F0R(i, n) {
        if(A[i] == B[i]) {
            c1 += A[i];
            c0 += !A[i];
            continue;
        }
        d1 += A[i];
        d0 += !A[i];
    }

    if(d0 and !d1) {
        if(c1 and c0) {
            cout << 2 << nl;    
        } else {
            cout << -1 << nl;
        }
    }
    else if(!d1) {
        cout << 0 << nl;
    }
    else if(d1 % 2) {
        cout << 1 << nl;
    }
    else {
        cout << 2 << nl;
    }
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


