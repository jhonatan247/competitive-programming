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
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

typedef vector<_vi> _vvi;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl;

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

const char nl = '\n';
const int MX = 100001; 

int n;
vector<_pi> conts;
int memo[1 << 10];

bool isValidGroup(int xIndx, int yIndx, int zIndx){
    _pi x = conts[xIndx];
    _pi y = conts[yIndx];
    _pi z = conts[zIndx];

    int rx = xIndx + 1;
    int ry = yIndx + 1;
    int rz = zIndx + 1;

    if(rx < y.fr or rx > y.sc) return false; 
    if(rx < z.fr or rx > z.sc) return false; 
    if(ry < x.fr or ry > x.sc) return false; 
    if(ry < z.fr or ry > z.sc) return false; 
    if(rz < x.fr or rz > x.sc) return false; 
    if(rz < y.fr or rz > y.sc) return false; 

    return true;
}

int dp(int mask) {
    if (mask == (1 << n) - 1) return 0;   // all used
    int &res = memo[mask];
    if (res != -1) return res;

    res = 0;
    // first unused person
    int i = 0;
    while (mask & (1 << i)) i++;

    // Option 1: skip person i
    res = max(res, dp(mask | (1 << i)));

    // Option 2: use i in a team with two other unused people
    for (int j = i + 1; j < n; j++) {
        if (mask & (1 << j)) continue;
        for (int k = j + 1; k < n; k++) {
            if (mask & (1 << k)) continue;
            if (isValidGroup(i, j, k)) {
                int newMask = mask | (1 << i) | (1 << j) | (1 << k);
                res = max(res, 1 + dp(newMask));
            }
        }
    }
    return res;
}


void solve() {
   cin >> n;

   F0R (i, n) {
       int a , b;
       cin>> a >> b;
       conts.pb(mp(a, b));
   }


    memset(memo, -1, sizeof(memo));
    cout << dp(0) << nl;

   
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

