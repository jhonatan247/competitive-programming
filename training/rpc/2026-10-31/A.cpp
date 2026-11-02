#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>
#include <numbers>

using namespace std;

typedef int64_t _ll;
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

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    _ld x1, y1;
    cin >> x1 >> y1;
    _ld x2, y2;
    cin >> x2 >> y2;
    _ld x3, y3;
    cin >> x3 >> y3;

    _ld a2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    _ld b2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    _ld c2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    _ld a = sqrt(a2);
    _ld b = sqrt(b2);
    _ld c = sqrt(c2);

    _ld ta = acos((b2 + c2 - a2) / (2 * b * c));
    _ld tb = acos((a2 + c2 - b2) / (2 * a * c));
    _ld tc = acos((b2 + a2 - c2) / (2 * b * a));
    
    _ld pi = 3.14159265358979323846;
    _ld pim = pi / 2;
    debug(ta, tb, tc, pim);

    _ld da = abs(pi - ta);
    _ld db = abs(pi - tb);
    _ld dc = abs(pi - tc);
    debug(da, db, dc);
    
    _ld mind = min({da, db, dc});

    if(da == mind) {
        
    } else if(db == mind) {
        
    } else {
        
    }
    
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


