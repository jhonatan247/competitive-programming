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
typedef complex<ld> _cd;

typedef pair<int, int> _pi;
typedef pair<ll,ll> _pl;
typedef pair<ld,ld> _pd;

typedef vector<int> _vi;
typedef vector<string> _vs;
typedef vector<ld> _vd;
typedef vector<ll> _vl;
typedef vector<cd> _vcd;
typedef vector<pi> _vpi;
typedef vector<pl> _vpl;

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

#define trav(a,x) for (auto& a : x)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--) 

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    _ll n;
    cin >> n;
    _vl a(n);
    
    int maxCi = 0;
    int maxCj = 0;
    bool isCnt = false;
    int currCi = 0;
    F0R(i, n){
        cin >> a[i];
        if(i > 0){
            if(a[i] == a[i - 1]){
                if(!isCnt){
                    currCi = i;
                    isCnt =  true;
                }
            }else if(isCnt){
                if(maxCj - maxCi < i - 1 - currCi){
                    maxCi = currCi;
                    maxCj = i - 1;
                } 
                isCnt = false;
            }
        }
    }
    if(isCnt and maxCj - maxCi < n - 1 - currCi){
        maxCi = currCi;
        maxCj = i - 1;
    }
    

    FOR(i, 1, n){
        
    }
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

