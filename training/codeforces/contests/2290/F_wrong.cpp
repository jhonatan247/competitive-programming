#ifdef LOCAL
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>,
    rb_tree_tag, tree_order_statistics_node_update>;

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
    
    vector<int> b(n);
    ordered_set<_ll> pos; 
    F0R(i, n) {
        cin >> b[i];
        pos.ins(i);
    }
    
    _vl ans(n);

    F0R(i, n) {
        _ll indx = -1;
        if(b[i] > 0) {
            auto it = pos.find_by_order(b[i] - 1);
            if(it == pos.end() or b[i] > (n - 1 -i)) goto impossible;
            indx = *it;
            pos.erase(it);
        } else {
            auto it = pos.find_by_order(n + b[i] - 1);
            if(it == pos.end() or b[i] < i) goto impossible;
            indx = *it;
            pos.erase(it);
        }
        debug(indx);
        ans[indx] = i + 1;
        debug(ans);
    }

    F0R(i, n) {
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << nl;
    return;

    impossible:
        cout << -1 << nl;
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


