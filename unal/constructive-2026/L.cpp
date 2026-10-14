#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 

void solve() {
    _ll u, v;
    cin >> u >> v;
    
    if(u > v or (v - u) % 2) {
        cout << -1 << nl;
        return;
    }

    if(v == 0) {
        cout << 0 << nl;
        return;
    }

    if(u == v) {
        cout << 1 << nl;
        cout << u << nl;
        return;
    }

    _ll k = (v - u) / 2;

    if((k & u) == 0) {
        cout << 2 << nl;
        cout << u + k << ' ' << k << nl;
        return;
    }

    cout << 3 << nl;
    cout << u << ' ' << k << ' ' << k << nl;
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
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}


