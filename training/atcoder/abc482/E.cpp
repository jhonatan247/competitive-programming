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
#define fill0(a) memset(a, 0, sizeof a)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';

int N;
_vi colors;
_vvi adj;

void find(int u, int p, int d, int& max_d, int& farthest, _vi& parent) {
    if (d > max_d) {
        max_d = d;
        farthest = u;
    }
    TRAV(v, adj[u]) {
        if (v != p) {
            parent[v] = u;
            find(v, u, d + 1, max_d, farthest, parent);
        }
    }
}

void collect(int u, int p, int d, int tgt_d, map<int, _ll>& freq) {
    if (d == tgt_d) {
        freq[colors[u]]++;
        return;
    }
    TRAV(v, adj[u]) {
        if (v != p) {
            collect(v, u, d + 1, tgt_d, freq);
        }
    }
}

void solve() {
    cin >> N;
    N++;
    
    adj.clear();
    colors.clear();
    
    adj.resize(N);
    colors.resize(N);
    
    FOR(i, 1, N - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    FOR(i, 1, N) {
        cin >> colors[i];
    }
     

    int max_d = -1, endpoint_A = 1;
    _vi parent(N + 1, 0);
    find(1, 0, 0, max_d, endpoint_A, parent);

    max_d = -1;
    int endpoint_B = endpoint_A;
    fill(parent.begin(), parent.end(), 0);
    find(endpoint_A, 0, 0, max_d, endpoint_B, parent);

    int diameter = max_d;

    _vi path;
    int curr = endpoint_B;
    while (curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    _ll ans = 0;

    if(diameter % 2) {
        int k = diameter / 2;
        int c1 = path[k];
        int c2 = path[k + 1];

        map<int, _ll> freq1, freq2;
        collect(c1, c2, 0, k, freq1);
        collect(c2, c1, 0, k, freq2);

        for(auto [color, count1] : freq1) {
            if(freq2.count(color)) {
                ans += count1 * freq2[color];
            }
        }
    } 
    else {
        int k = diameter / 2;
        int center = path[k];

        map<int, _ll> global_freq;
        vector<map<int, _ll>> subtree_freqs;

        TRAV(neighbor, adj[center]) {
            map<int, _ll> sub_freq;
            collect(neighbor, center, 1, k, sub_freq);
            
            for (auto [color, count] : sub_freq) {
                global_freq[color] += count;
            }
            subtree_freqs.push_back(sub_freq);
        }

        for(auto [color, total_count] : global_freq) {
            ans += (total_count * (total_count - 1)) / 2;
        }
        
        for(auto const& sub_freq : subtree_freqs) {
            for(auto [color, sub_count] : sub_freq) {
                ans -= (sub_count * (sub_count - 1)) / 2;
            }
        }
    }

    cout << ans << nl;

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


