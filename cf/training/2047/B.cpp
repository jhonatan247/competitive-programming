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

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> lcnt(27, 0);
    vector<int> lindx(27, 0);

    F0R(i, sz(s)) {
        int l = s[i] - 'a';
        lcnt[l]++;
        lindx[l] = i;
    }
    
    int mincnt = n + 1;
    int minindx = 0;
    int maxcnt = 0;
    int maxindx = 0;

    F0R(i, sz(lcnt)) {
        if(lcnt[i] == 0) continue;

        if(lcnt[i] >= maxcnt){
            maxcnt = lcnt[i];
            maxindx = lindx[i];
        }
        if(lcnt[i] < mincnt){
            mincnt = lcnt[i];
            minindx = lindx[i];
        }
    }

    s[minindx] = s[maxindx];

    cout << s << nl;
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

