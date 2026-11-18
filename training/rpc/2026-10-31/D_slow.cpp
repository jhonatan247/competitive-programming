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
    
    _vb ans(n + 1, false);

    F0R(i, n - 2) {
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];
        int mx = max({a, b, c});
        int mn = min({a, b, c});

        if(a != mx and a != mn) ans[a] = true;
        if(b != mx and b != mn) ans[b] = true;
        if(c != mx and c != mn) ans[c] = true;
    }


    ordered_set<int> G;
    G.ins(arr[0]);
    G.ins(arr[1]);
    G.ins(arr[2]);
    
    for(_ll i = 3; i + 1 < n; i+=2) {
        G.ins(arr[i]);
        G.ins(arr[i + 1]);
        ans[*G.find_by_order(sz(G) / 2)] = true;
    }

    for(_ll i = 0; i + 1 < n - 3; i+=2) {
        G.erase(arr[i]);
        G.erase(arr[i + 1]);
        ans[*G.find_by_order(sz(G) / 2)] = true;
    }


    F0R(i, n) {
        if(i) cout << ' ';
        if(ans[arr[i]]) cout << "YES";
        else cout << "NO";
    }
    cout << nl;
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


