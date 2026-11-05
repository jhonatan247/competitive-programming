#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef __int128_t _i128;

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

typedef tuple<int,int,int> _ti;
typedef tuple<_ll,_ll,_ll> _tl;
typedef vector<_ti> _vti;
typedef vector<_tl> _vtl;

#define _fr(x) get<0>(x)
#define _sc(x) get<1>(x)
#define _th(x) get<2>(x)
#define _fo(x) get<3>(x)
#define mt(...) make_tuple(__VA_ARGS__)

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';

bool half(_tl &p) {
    return _sc(p) > 0 or (_sc(p) == 0 and _fr(p) > 0);
}

_ll cross(_tl &a, _tl &b) { 
    return  _fr(a) * _sc(b) - _sc(a) * _fr(b);
}

_ll dot(_tl &a, _tl &b) { 
    return  _fr(a) * _fr(b) + _sc(a) * _sc(b);
}

_ll dot2(_tl &a, _tl &b) { 
    return dot(a, b) * dot(a, b);
}

bool comparator(_tl &a, _tl &b) {
    if(half(a) == half(b)) {
        return cross(a, b) > 0;
    }
    return half(a) > half(b);
}

_ll norm2(_tl &p) { 
    return  _fr(p) * _fr(p) + _sc(p) * _sc(p);
}


bool angle_less(_tl &a, _tl &b, _tl &c, _tl &d) {
    _i128 dot_ab = dot(a, b);
    _i128 dot_cd = dot(c, d);

    _i128 norm_ab = norm2(a) * norm2(b);
    _i128 norm_cd = norm2(c) * norm2(d);
    
    if(dot_ab >= 0 and dot_cd < 0) return true;

    if(dot_ab < 0 and dot_cd >= 0) return false;

    _i128 angle_ab = dot_ab * dot_ab * norm_cd;
    _i128 angle_cd = dot_cd * dot_cd * norm_ab;


    if(dot_ab >= 0) {
        return angle_ab > angle_cd;
    } else {
        return angle_ab < angle_cd;
    }
}


void solve() {
    int n;
    cin >> n;
    
    _vtl points(n);
    F0R(i, n) {
        _ll fr, sc;
        cin >> fr >> sc;
        points[i] = mt(fr, sc, i + 1);
    }

    sort(all(points), comparator);
    
    debug(points);

    int a = n - 1;
    int b = 0;

    F0R(i, n - 1) {
        if(angle_less(points[i], points[i + 1], points[a], points[b])) {
            a = i;
            b = i + 1;
        }
    }

    cout << _th(points[a]) << ' ' << _th(points[b]) << nl;
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


