#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long _ll;
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

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 

// Disjoint sets

_vi P;
_vi SZ;

int getParent(int a) { 
    int curr = a;
    assert(a < sz(P));
    assert(a > 0);
    while(P[curr] != curr) {
        curr = P[curr];
    }
    P[a] = curr;
    return curr;
}

void join(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a == b) return;
    if(SZ[a] > SZ[b]) {
        P[b] = a;
        SZ[a] += SZ[b];
    } else {
        P[a] = b;
        SZ[b] += SZ[a];
    }
}


void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    n++;
    vector<int> arr(n);
    FOR (i, 1, n) {
        cin >> arr[i];
    }

    P = _vi(n);
    SZ = _vi(n);
    FOR(i, 1, n) {
        P[i] = i;
        SZ[i] = 1;
    }


    FOR(i, 1, n) {
        if(i + x < n) {
            join(i, i + x);
        }
        if(i + y < n) {
            join(i, i + y);
        }
        if(i - x >= 1) {
            join(i, i - x);
        }
        if(i - y >= 1) {
            join(i, i - y);
        }
    }

    FOR(i, 1, n) {
        if(getParent(i) != getParent(arr[i])) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}


