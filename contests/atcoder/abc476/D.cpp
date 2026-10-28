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

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
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

void solve() {
    _ll n, m, k;
    cin >> n >> m >> k;
    debug(n, m, k);
    n++;
    m++;

    _ll x, y;
    cin >> x >> y;

    vector<_ll> A(n, 0);
    FOR(i, 1, n) {
        cin >> A[i];
    }
    vector<_ll> B(m, 0);
    FOR(i, 1, m) {
        cin >> B[i];
    }

    sort(all(A));
    sort(all(B));
    
    _vl sumA(n, 0);
    
    FOR(i, 1, n) {
        sumA[i] = sumA[i - 1] + A[i];
    }
    
    _vpl sumB;
    sumB.pb(mp(0, 0));

    int maxBcnt = 0;
    
    FOR(i, 1, m) {
        _ll price = sumB[i - 1].fr + B[i];
        _ll bills = sumB[i - 1].sc + (B[i] + (k - 1)) / k;
        sumB.pb(mp(price, bills));
        
        if(bills <= y) {
            maxBcnt ++;
        } else {
            break;
        }
    }

    int Acnt = 0;
    
    _ll ans = maxBcnt;

    F0Rd(Bcnt, maxBcnt + 1) {
        _ll change = x + k * y - sumB[Bcnt].fr;
        while(Acnt < n - 1 and sumA[Acnt + 1] <= change) {
             Acnt++;
        }
        ans = max(ans, Bcnt + Acnt); 
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


