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

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

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

int compute_dist(_vvi &adj, int root) {
    int ops = 0;
    
    set<int> children(all(adj[root]));

    while(sz(children)) {
        int child = *children.begin();
        if(!sz(adj[child])) {
            children.erase(child);
        } else {
            TRAV(a_node, adj[child]) {
                ops++;
                children.ins(a_node);
                children.ins(all(adj[a_node]));
                adj[a_node].clear();
            }
            children.erase(child);
        }
    }
    return ops;
}

_vvi build_directed_adj(_vvi &adj, int root) {
    _vvi directed_adj(sz(adj));
    _vb visited(sz(adj), false);

    queue<int> bfs;
    bfs.push(root);
    visited[root] = true;

    while(sz(bfs)) {
        int curr = bfs.front();
        bfs.pop();
        
        TRAV(child, adj[curr]) {
            if(!visited[child]) {
                directed_adj[curr].pb(child);
                bfs.push(child);
                visited[child] = true;
            }
        }
    }

    return directed_adj;
}

int get_tree_extreme(_vvi &adj, int start) {
    vector<bool> visited(sz(adj), false);

    queue<_pi> bfs;
    bfs.push(mp(start, 0));
    int max_dist = 0;
    int extreme = start;

    while(sz(bfs)) {
        auto curr = bfs.front();
        bfs.pop();
        int next_dist = curr.sc + 1;
        TRAV(child, adj[curr.fr]) {
            if(!visited[child]) {
                if(max_dist < next_dist) {
                    max_dist = next_dist;
                    extreme = child;
                }
                bfs.push(mp(child, next_dist));
                visited[child] = true;
            }
        }
    }

    return extreme;
}


void solve() {
    int n;
    cin >> n;
    n++;
    
    _vvi adj(n);
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int root = get_tree_extreme(adj, 1);

    _vvi adj_root = build_directed_adj(adj, root);
    int ops_root = compute_dist(adj_root, root);

    _vvi adj_child = build_directed_adj(adj, adj[root][0]);
    int ops_child = compute_dist(adj_child, adj[root][0]);

    cout << min(ops_root, ops_child) << nl;
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


