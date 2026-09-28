#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#pragma GCC optimize ("O3")

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
    _ll n, x;
    cin >> n >> x;

    vector<_ll> arr(n);
    F0R (i, n) {
        cin >> arr[i];
    }

    int i = 0;
    _ll sum = 0;
    int cnt = 0;
    F0R(j, n) {
        sum += arr[j];
        if(sum < x){
            continue;
        }
        while(sum > x){
            sum -= arr[i++];
        }
        if (sum == x){
            cnt++;
        }
    }
    cout << cnt << nl;
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

