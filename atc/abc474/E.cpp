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

typedef tuple<int,int,int> _ti;
typedef tuple<_ll,_ll,_ll> _tl;
typedef vector<_ti> _vti;
typedef vector<_tl> _vtl;

#define _fr(x) get<0>(x)
#define _sc(x) get<1>(x)
#define _th(x) get<2>(x)
#define _fo(x) get<3>(x)
#define mt(...) make_tuple(__VA_ARGS__)  

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define fill0(a) memset(a, 0, sizeof a)
#define fill(a, v) memset(a, v, sizeof a)
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
    
    _vti arr(n);
    
    F0R(i, n) {
        _ll a , b;
        cin >> a;
        cin >> b;
        arr[i] = mt(a - b, a, b);
    }

    sort(all(arr), greater<_ti>());

    _vl B(n);
    B[0] = _th(arr[0]);
    _vl A(n);
    A[0] = _sc(arr[0]);
    
    _ll a0 = _sc(arr[0]);
    int a0i = 0;

    FOR(i, 1, n) {
        B[i] += B[i - 1] + _th(arr[i]);
        A[i] += A[i - 1] + _sc(arr[i]);
        if(_sc(arr[i]) <= a0) {
            a0 = _sc(arr[i]);
            a0i = i; 
        }
    }

    _ll sumA = A[n - 1];
    _ll ans = sumA;

    FOR(k, 1, max(a0i + 1, (n + 1) / 2 + 1)) {
        _ll curr = B[k - 1] + (sumA - A[k - 1]) + a0 * max(0, k * 2 - n);
        if(curr > ans) break;
        ans = curr;
    }

    cout << ans << nl;
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



