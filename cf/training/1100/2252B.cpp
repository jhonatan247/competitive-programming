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
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    char prev = s[0];
    int currsz = 0;
    int e1 = 0;
    int e0 = 0;
    FOR(i, 1, n) {
        if(prev == s[i]) currsz++;
        if(prev != s[i] or i == n - 1) {
            if(prev == '1') e1 += currsz;
            else e0 += currsz;
            currsz = 0;
        }
        prev = s[i];
    }

    if(abs(e1 - e0) > 1) {
        if(e0 < e1) {
            e0 += s[0] == '0';
            if(e1 - e0 > 1) 
                e0 += s[n - 1] == '0';
        }
        if(e1 < e0) {
            e1 += s[0] == '1';
            if(e0 - e1 > 1) 
                e1 += s[n - 1] == '1';
        }
    }

    if(abs(e1 - e0) <= 1) {
        cout << e1 + e0 << nl;
    } else {
        cout << -1 << nl;
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


