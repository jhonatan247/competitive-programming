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
    int k;
    cin >> k;
    
    int a1, b1;
    cin >> a1 >> b1;
    
    int a2, b2;
    cin >> a2 >> b2;
    
    bool won1 = a1 > b1;
    bool won2 = a2 > b2;

    if((a1 + a2) - (b1 + b2) > k) {
        cout << "NO" << nl;
    } else if((a1 + a2) - (b1 + b2) == k and won1 and won2) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
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


