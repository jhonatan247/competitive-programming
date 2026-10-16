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
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int zcount = 0;

    while(s[n - zcount - 1] == '0') {
        zcount++;
    }
    
    int maxzcount = zcount;

    F0R(i, n) {
       if(s[i] == '0') {
           zcount++;
           maxzcount = max(maxzcount, zcount);
       } else {
           zcount = 0;
       }
    }

    cout << maxzcount << nl;
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


