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
 
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
   int n;
   cin >> n;
   
   vector<int> arr(n);
   F0R (i, n) {
       cin >> arr[i];
   }
   
   int sign = 1;
   vector<int> ops;
   F0Rd(i, n) {
       if(arr[i] * sign > 0) {
           ops.pb(i + 1);
           sign *= -1;
       }
   }

   cout << sz(ops) << endl;
   F0R(i, sz(ops)) {
       if(i) cout << ' ';
       cout << ops[i];
   }
   cout << endl;
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

