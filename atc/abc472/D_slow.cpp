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

typedef tuple<int,int,int> _ti;
typedef tuple<_ll,_ll,_ll> _tl;
typedef vector<_ti> _vti;
typedef vector<_tl> _vtl;

#define _fr(x) get<0>(x)
#define _sc(x) get<1>(x)
#define _th(x) get<2>(x)
#define _fo(x) get<3>(x)
#define mt(...) make_tuple(__VA_ARGS__)

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
    int h, w, k;
    cin >> h >> w >> k;
    
    vector<string> grid(h);
    F0R(i, h) {
        cin >> grid[i];
    }

    _vb safeCol(h, false);
    int bombcnt = 0;
    F0R(i, h) {
        F0R(j, w) {
            if(grid[i][j] == '#') {
                bombcnt++;
            }
        }
    }

    F0R(j, h) {
        bool isSafe = true;
        F0R(i, w) {
            if(grid[j][i] == '#') {
                isSafe = false;
                break;
            }
        }
        if(isSafe) {
            safeCol[j] = true;
        }
    }
    

    _vb safeRow(w, false);

    F0R(i, w) {
        bool isSafe = true;
        F0R(j, h) {
            if(grid[j][i] == '#') {
                isSafe = false;
                break;
            }
        }
        if(isSafe) {
            safeRow[i] = true;
        }
    }

    _vpi safeCell;
    F0R(i, h) {
        F0R(j, w) {
            if(safeRow[j] and safeCol[i]) {
                safeCell.pb(mp(i, j));
            }
        }
    }

    
    _vvb visited(h, _vb(w, false));
    
    debug(safeCell);

    int ans = 0;
    int tgt = h * w - bombcnt;
    
    TRAV(cell, safeCell) {
        queue<_ti> bfs;
        bfs.push(mt(cell.fr, cell.sc, 0));
        
        debug(cell);

        if(!visited[cell.fr][cell.sc]) {
            visited[cell.fr][cell.sc] = true;
            ans++;
        }
        
        while(sz(bfs)) {
            auto curr = bfs.front();
            bfs.pop();

            int j = _fr(curr);
            int i = _sc(curr);
            int depht = _th(curr);
            int nextDepht = depht + 1;
            debug(i, j);
            debug(nextDepht);
            if(nextDepht > k) continue; 

            if(j > 0 and grid[j - 1][i] == '.') {
                if(!visited[j - 1][i]) {
                    ans++;
                    visited[j - 1][i] = true;
                }
                bfs.push(mt(j - 1, i, nextDepht));
            }
            if(j < h - 1 and grid[j + 1][i] == '.') {
                if(!visited[j + 1][i]) {
                    ans++;
                    visited[j + 1][i] = true;
                }
                bfs.push(mt(j + 1, i, nextDepht));
            }
            if(i > 0 and grid[j][i - 1] == '.') {
                if(!visited[j][i - 1]) {
                    ans++;
                    visited[j][i - 1] = true;
                }
                bfs.push(mt(j, i - 1, nextDepht));
            }
            if(i < w - 1 and grid[j][i + 1] == '.') {
                if(!visited[j][i + 1]) {
                    ans++;
                    visited[j][i + 1] = true;
                }
                bfs.push(mt(j, i + 1, nextDepht));
            }
            debug(bfs);
            if(ans == tgt) break;
        } 
        if(ans == tgt) break;
    }

    F0R(i, sz(visited)) {
        debug(visited[i]);
    }

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


