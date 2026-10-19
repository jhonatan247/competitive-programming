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
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n, q;
    cin >> n >> q;
    
    map<int, char> tiled;
    map<int, char> untiled;
    char color = 'a';

    F0R(i, q) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            if(tiled.count(x)) {
                untiled[x] = tiled[x];
                tiled.erase(x);
            } else if (untiled.count(x)) {
                tiled[x] = untiled[x];
                untiled.erase(x);
            } else {
                tiled[x] = color;
            }
        } else {
            cin >> color;
            untiled.clear();
        }
    }

    FOR(i, 1, n + 1) {
        if(tiled.count(i)) {
            cout << tiled[i];
        } else if (untiled.count(i)) {
            cout << untiled[i];
        } else {
            cout << color;
        }
    }
    cout << nl;
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


