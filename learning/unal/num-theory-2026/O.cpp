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

const int INF  =  1e9;
const int NINF = -1e9;

void solve() {
    int n;
    cin >> n;
    n++;
    
    set<int> unique;
    bool one_present = false;
    FOR(i, 1, n) {
        int num;
        cin >> num;
        if(num == 1) {
            one_present = true;
        } else {
            unique.ins(num);
        }
    }

    vector<int> nums(all(unique));
    

    vector<int> dp(n, INF);
    dp[1] = 0;
    FOR(i, 1, n) {
        if(dp[i] == INF) continue;
        TRAV(num, nums) {
            if(i * num >= n) break;
            dp[i * num] = min(dp[i * num], dp[i] + 1);
        }
    }

    FOR(i, 1, n) {
        if(i > 1) cout << ' ';
        if(i == 1) {
            cout << (one_present ? 1 : -1);
        } else {
            cout << (dp[i] == INF ? -1 : dp[i]);
        }
    }
    cout << nl;
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


