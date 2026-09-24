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
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
     int n = uid(3, 10);
     cout << n << nl;
     vector<int> a;
     stack<int> b;

     F0R(i, n) {
        if(i == 0) a.pb(1);
        else {
            int prev = a[i - 1];
            a.pb(uid(prev, i + 1));
        }

        int j = n - i - 1;
        if(i == 0) b.push(n);
        else {
            int next = b.top();
            b.push(uid(j + 1, next));
        }
     }

     F0R(i, n) {
         cout << a[i] << ' ' << b.top() << nl;
         b.pop();
     }
     cout << nl;
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

