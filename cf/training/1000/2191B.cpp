#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

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

int MEX(vector<int> &arr, int l, int r) {
    int curr = -1;
    FOR(i, l, r + 1) {
        if(arr[i] == curr) continue;
        if(arr[i] == curr + 1) curr++;
        else return curr;
    }
    return curr;
}

void solve() {
     int n;
     cin >> n;
     vector<int> arr(n);
     F0R (i, n) {
         cin >> arr[i];
     }
     sort(all(arr));

     F0R(i, n - 1) {
         if(MEX(arr, 0, i) == MEX(arr, i + 1, n - 1)) {
             cout << "NO" << nl;
             return;
         }
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


