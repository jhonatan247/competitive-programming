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
    
    vector<_ll> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }

    _vpl smin(n);
    smin[n - 1] = mp(arr[n - 1], n - 1);

    F0Rd(i, n - 1) {
        if(arr[i] < smin[i + 1].fr) {
            smin[i] = mp(arr[i] , i);
        } else {
            smin[i] = smin[i + 1];
        }
    }


    _vl cnt(n);
    F0R(i, n) {
        if(smin[i].fr < arr[i]) {
            cnt[i]--;
        }
    }

    set<int> prev;
    _ll max_cnt = 0;
    _ll moves = 0;
    F0R(i, n) {
        if(smin[i].sc == i) continue;
        moves += arr[i] - smin[i].fr;
        cnt[smin[i].sc]++;
        max_cnt = max(max_cnt, cnt[smin[i].sc]); 
    }

    if(max_cnt) {
        moves += max_cnt;
    }

    cout << moves << nl;

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


