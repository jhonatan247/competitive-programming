#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "local/debug.h"
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long _ll;
typedef long double _ld;
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<bool> _vb;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

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

const char OBJ = '*';
const char EMPT = '.';


bool isCentroid(_vs &b, int y, int x) {
    if(x == 0 or y == 0) return false;
    if(y == sz(b) - 1 or x == sz(b[y]) - 1) return false;
        
    if(b[y][x] == EMPT) return false;
    if(b[y - 1][x] == EMPT or b[y + 1][x] == EMPT) return false;
    if(b[y][x - 1] == EMPT or b[y][x + 1] == EMPT) return false;
    if(b[y - 1][x - 1] == OBJ or b[y + 1][x + 1] == OBJ) return false;
    if(b[y - 1][x + 1] == OBJ or b[y + 1][x - 1] == OBJ) return false;
    
    return true;
}

bool isValidV(_vs &b, int y, int x) {
    assert(x > 0 and x < sz(b[y]) - 1);

    if(b[y][x - 1] == OBJ) return false;
    if(b[y][x + 1] == OBJ) return false;
    return true;
}

bool isValidH(_vs &b, int y, int x) {
    assert(y > 0 and y < sz(b) - 1);

    if(b[y - 1][x] == OBJ) return false;
    if(b[y + 1][x] == OBJ) return false;
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> b(n);
    F0R(i, n) {
        cin >> b[i];
    }

    int ans = 0;
    F0R(y, n) {
        F0R(x, m) {
            if(isCentroid(b, y, x)) {
                debug(x, y);
                int ucnt = 0;
                int dcnt = 0;
                int lcnt = 0;
                int rcnt = 0;
                F0Rd(i, y) {
                    if(b[i][x] == EMPT) break;
                    if(isValidV(b, i, x)) {
                        ucnt++;
                    } else {
                        goto invalid;
                    }
                }
                debug(ucnt);
                FOR(i, y + 1, n) {
                    if(b[i][x] == EMPT) break;
                    if(isValidV(b, i, x)) {
                        dcnt++;
                    } else {
                        goto invalid;
                    }
                }
                debug(dcnt);
                if(ucnt >= dcnt) goto invalid;
                F0Rd(i, x) {
                    if(b[y][i] == EMPT) break;
                    if(isValidH(b, y, i)) {
                        lcnt++;
                    } else {
                        goto invalid;
                    }
                }
                debug(lcnt);
                if(ucnt != lcnt) goto invalid;
                FOR(i, x + 1, m) {
                    if(b[y][i] == EMPT) break;
                    if(isValidH(b, y, i)) {
                        rcnt++;
                    } else {
                        goto invalid;
                    }
                }
                debug(rcnt);
                if(ucnt != rcnt) goto invalid; 
                
                ans++;
            }
            invalid:
                continue;
        }
    }
   
    cout << ans << nl;
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
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


