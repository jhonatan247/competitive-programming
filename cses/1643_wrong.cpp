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
    vector<int> arr(n);
    vector<_ll> acum(n);
    F0R (i, n) {
        cin >> arr[i];
        if(i) acum[i] = acum[i - 1] +  arr[i];
        else acum[i] = arr[i];
    }
    vector<_ll> acumr(n);
    
    F0Rd(i, n) {
        if(i < n - 1) acumr[i] = acumr[i + 1] + arr[i];
        else acumr[i] = arr[i];
    }

    _ll minR = LLONG_MAX;
    int minrIndx = -1;
    _ll minL = LLONG_MAX;
    int minlIndx = -1;

    F0R(i, n) {
        if(acum[i] < minR){
            minR
        }
    }


    

}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;
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

