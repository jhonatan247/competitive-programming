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

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvb> _vvvb;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl;

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

void solve() {
    int n;
    cin >> n;
    vector<string> table(2);
    F0R(i, 2) {
        cin >> table[i];
    }

    _vvb used(2, _vb(n, false));

    int pairs = n;
    
    F0R(x, n) {
        F0R(y, 2) {
            debug(used);
            debug(pairs);
            if(used[y][x]) continue;
            if(x > 0 and y == 1 and !used[y][x - 1] and used[y - 1][x - 1]) {
                used[y][x] = true;
                used[y][x - 1] = true;
                continue;
            }
            if(x > 0 and y == 0 and !used[y][x - 1] and used[y + 1][x - 1]) {
                used[y][x] = true;
                used[y][x - 1] = true;
                continue;
            }
            if(y == 0 and !used[y + 1][x]) {
                if(table[y][x] == table[y + 1][x]) {
                    pairs--;
                    used[y][x] = true;
                    used[y + 1][x] = true;
                    continue;
                }
            }
            if(x < n - 1 and !used[y][x + 1]) {
                if(table[y][x] == table[y][x + 1]) {
                    pairs--;
                    used[y][x] = true;
                    used[y][x + 1] = true;
                    continue;
                }
            }
        }
        debug(used);
        debug(pairs);
    }
   
    cout << pairs << nl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


