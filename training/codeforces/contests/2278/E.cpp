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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>,
    rb_tree_tag, tree_order_statistics_node_update>;


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
    int n;
    cin >> n;
    
    vector<_ll> arr(n);
    ordered_set<int> pos;
    _ll absum = 0;
    F0R(i, n) {
        cin >> arr[i];
        if(arr[i] < 0) pos.ins(i);
        
        arr[i] = abs(arr[i]);
        absum += arr[i];
    }

    debug(pos);

    while(sz(pos)){
        bool reduced = false;
        
        int curr = *pos.find_by_order(0);
        int i = 1;
        while(i < sz(pos)) {
            int next = *pos.find_by_order(i);
            if((next - curr) % 2) {
                pos.erase(curr);
                pos.erase(next);
                reduced = true;
                if(i < sz(pos)) {
                    curr = *pos.find_by_order(i - 1);
                }
            } else {
                i++;
                curr = next;
            }
        }

        if(!reduced) break;
    }
    debug(pos);

    set<_pi> opt;
    TRAV(p, pos) {
        opt.ins(mp(arr[p], p));
        if(p) {
            opt.ins(mp(arr[p - 1], p - 1));
        }
        if(p < n - 1) {
            opt.ins(mp(arr[p + 1], p + 1));
        }
    }

    int i = 0;
    TRAV(o, opt) {
        absum -= 2 * o.fr;
        i++;
        if(i == sz(pos)) break;
    }

    cout << absum << nl;

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


