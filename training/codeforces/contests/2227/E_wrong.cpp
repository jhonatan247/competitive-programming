#ifdef LOCAL
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)
#define P_TRAV(k, a, x) for (auto& [k, a] : x)  

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

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }

    multiset<int> cnt;
    _ll max_moves = 0;
    int max_indx = -1;
    _ll max_uppr = -1;
    F0R(i, n) {
        _ll curr = distance(cnt.lower_bound(arr[i]), cnt.end());
        if(max_moves and arr[i] > arr[max_indx]) {
            curr -= max_uppr;
        }
        if(curr > max_moves) {
            max_moves = curr;
            max_indx = i;
            max_uppr = distance(cnt.upper_bound(arr[i]), cnt.end());
        }
        cnt.ins(arr[i]);
        debug(i, arr[i], curr);
    }
    debug(max_moves);
    
    cnt.clear();
    _ll ans = 0;
    if(max_moves) {
        arr[max_indx]--;
    }
    debug(arr);
    F0Rd(i, n) {
        if(!sz(cnt)) {
            cnt.ins(arr[i]);
            continue;
        }
        int fr = *cnt.begin();
        cnt.ins(arr[i]);
        debug(i, fr);
        if(fr >= arr[i]) continue;
        ans += arr[i] - fr;
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


