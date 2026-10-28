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
    int n, v;
    cin >> n >> v;
    
    vector<int> arr(n);
    F0R (i, n) {
        cin >> arr[i];
    }
    

    int maxW = 0;

    F0R(i, n) {
        int a = arr[i];
        F0R(j, n) {
            if(j == i) continue;
            int b = arr[j];
            F0R(k, n) {
                if(k == i or k == j) continue;
                int c = arr[k];
                if(i + j + k + 3 > v) continue;
                maxW = max(maxW, a + b + c);
            }
        }
    }
    cout << maxW << nl;
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

