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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> w(n);
    F0R (i, n) {
        cin >> w[i];
    }
    
    vector<int> r(m);
    F0R (i, m) {
        cin >> r[i];
    }

    sort(all(w), greater<int>());
    sort(all(r), greater<int>());

    int j = 0;
    F0R(i, k) {
       int curr = w[i];
       while(j < m and curr - r[j] >= 0){
            curr -= r[j];
            j++;
       }
       if(j == m) break;
       r[j] -= curr;
    }

    if(j == m) cout << "Yes";
    else cout << "No";
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

