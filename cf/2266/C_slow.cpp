#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#pragma GCC optimize ("O3")

#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif 

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long _ll;
typedef long double _ld;
 
#define trav(a,x) for (auto& a : x)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX =  100001; 

int minSort(string& s, int i, int j){
    if(i >= j) return 0;
    int f0 = -1;
    int l1 = j + 1;
    FOR(k, i, j + 1){
        if(k > f0 and s[k] == '0') f0 = k;
        if(k < l1 and s[k] == '1') l1 = k;
    }
//    cout << "Debug: " << i << "," << j << ":" << f0 << "," << l1 << endl;
    if(f0 < l1)
        return 0;

    return 1 + min(minSort(s, l1 + 1, j), minSort(s, i, f0 - 1));
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    if(s[0] == '1'){
        int cnt = 0;
        F0R(i, n){
            if(s[i] == '0') cnt ++;
        }
        cout << cnt << nl;
        return;
    }
    cout << minSort(s, 0, n - 1) << endl;
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

