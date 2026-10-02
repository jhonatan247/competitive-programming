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

    vector<_ll> arr(n*m);
    F0R (i, n*m) {
        cin >> arr[i];
    }
    
    sort(all(arr));

    _ll min1 = arr[0];
    _ll min2 = arr[1];
    _ll max1 = arr[sz(arr) - 1];
    _ll max2 = arr[sz(arr) - 2];

    int n_ = min(n, m);
    int m_ = max(n, m);

    _ll ans1 = (max1 -  min1) * (n_ * (m_ - 1)) + (max2 - min1)*(n_ - 1);
    
    _ll ans2 = (max1 -  min1) * (n_ * (m_ - 1)) + (max1 - min2)*(n_ - 1);
    
    cout << max(ans1, ans2) << endl;
    
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

