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

void solve() {
    int H, W;
    cin >> H >> W;
    
    _ll K;
    cin >> K;
    
    vector<string> grid(H);
    F0R(i, H) {
        cin >> grid[i];
    }
    
    _vb bombR(H, false);
    _vb bombC(W, false);
    F0R(i, H) {
        F0R(j, W) {
            if(grid[i][j] == '#') {
                bombR[i] = true;
                bombC[j] = true;
            }
        }
    }

    _vvi dist(H, _vi(W, W * H));
    
    queue<_pi> bfs;
    F0R(i, H) {
        F0R(j, W) {
            bool isSafe = !bombR[i] and !bombC[j];
            if(isSafe) {
                bfs.push(mp(i, j));
                dist[i][j] = 0;
            }
        }
    }

    int ans = 0;

    _vpi moves;
    moves.pb(mp(1 , 0));
    moves.pb(mp(-1 , 0));
    moves.pb(mp(0 , 1));
    moves.pb(mp(0 , -1));

    while(sz(bfs)) {
        auto curr = bfs.front();
        int i = curr.fr;
        int j = curr.sc;

        bfs.pop();
        ans++;

        if(dist[i][j] == K) continue;

        int nextDist = dist[i][j] + 1;

        TRAV(mv, moves) {
            int nexti = i + mv.fr;
            int nextj = j + mv.sc;
            
            if(nexti < 0 or nexti > H - 1) continue;
            if(nextj < 0 or nextj > W - 1) continue;
            if(grid[nexti][nextj] == '#') continue;
            if(dist[nexti][nextj] <= nextDist) continue;
            
            dist[nexti][nextj] = nextDist;
            bfs.push(mp(nexti, nextj));
        }
    }

    debug(dist);

    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    #warning "LOCAL ONLY: reading T for multi-test"
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


