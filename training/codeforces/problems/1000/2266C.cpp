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
    string s_;
    cin >> s_;
    
    int left = 0, right = 0;
    
    bool * s = new bool[n];
    F0R(i, n) {
        s[i] = s_[i] == '1';
        right += !s[i];
    }
    if(s[0]){
        cout << right << nl;
        return;
    }

    int i = 0;
    int minsum = INT_MAX;
    while(true) {
        while(i < n and !s[i]) {
            i++;
            right--;
        }
        if(i >= n) break;
        minsum = min(minsum, left + right);
        left++;
        i++;
    }

    cout << min(minsum, left) << nl;
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

