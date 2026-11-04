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

const _ll MX = 200001;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    _vi arr(n);
    map<int, _pi> cnt;
    F0R(i, n) {
        cin >> arr[i];
        if(cnt.count(arr[i])) {
            cnt[arr[i]].fr++;
        } else {
            cnt[arr[i]] = mp(1, 0);
        }
    }

    int psum = 0;
    for(auto &e : cnt) {
        psum += e.sc.fr;
        e.sc.sc = psum;
    }


    _ll ans = 0;
    while(sz(cnt)) {
        auto e = *cnt.begin();
        if(e.fr >= r) break;
        
        if(e.sc.fr <= 1) {
            cnt.erase(cnt.begin());
        } else {
            cnt.begin()->sc.fr--;
        }
        
        auto start = cnt.lower_bound(l - e.fr);
        if(start == cnt.end()) continue;
        
        auto end = cnt.upper_bound(r - e.fr);
        if(end == cnt.begin()) continue;
        --end;
        
        int add = end->sc.sc - start->sc.sc + start->sc.fr;
        ans += add;
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


