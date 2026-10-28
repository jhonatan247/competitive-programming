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

template<typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }

    _vpi sorted(n);
    F0R(i, n) {
        int coprimes = 0;
        F0R(j, n) {
            if(i == j) continue;
            if(gcd(arr[i], arr[j]) == 1) {
                coprimes++;
            }
        }
        sorted[i] = mp(coprimes, i);
    }

    sort(all(sorted), greater<_pi>());
    
    _vi colors(n, 0);
    
    _vvi groups;

    F0R(i, n) {
        bool grouped = false;
        auto curr = sorted[i];

        F0R(j, sz(groups)) {
            auto & group = groups[j];
            
            bool valid = true;
            TRAV(item, group) {
                if(gcd(arr[curr.sc], item) == 1) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                grouped = true;
                group.pb(arr[curr.sc]);
                colors[curr.sc] = j + 1;
                break;
            }
        }

        if(!grouped) {
            _vi ngroup;
            ngroup.pb(arr[curr.sc]);
            groups.pb(ngroup);
            colors[curr.sc] = sz(groups);
        }
    }

    cout << sz(groups) << nl;
    F0R(i, n) {
        if(i) cout << ' ';
        cout << colors[i];
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


