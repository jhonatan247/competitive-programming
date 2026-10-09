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
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    F0R (i, n) {
        cin >> a[i];
    }
    vector<int> b(m);
    F0R (i, m) {
        cin >> b[i];
    }

    if(2 * m > n) {
        cout << "NO" << nl;
        return;
    }
    
    sort(all(a));
    sort(all(b));

    int midIndx = m;
    F0R(i, m) {
        if(a[i] > b[i]) {
            cout << "NO" << nl;
            return;
        }
        while(midIndx < n and a[midIndx] < b[i]) midIndx++;
        if(midIndx == n) {
            cout << "NO" << nl;
            return;
        }
        midIndx++;
    }
    cout << "YES" << nl;

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


