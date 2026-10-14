#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const int MX = 100001; 

void solve() {
    int n;
    cin >> n;
    _vpi arr(n);
    set<int> elements;
    bool duplicated = false;
    bool sorted = true;
    int prev = 0;
    F0R (i, n) {
        int a;
        cin >> a;
        arr[i] = mp(a, i);
        if(elements.count(a)) {
            duplicated = true;
        } else {
            elements.ins(a);
        }
        if(sorted and a < prev) {
            sorted = false;
        }
        prev = a;
    }

    if(n == 1 or sorted or duplicated) {
        cout << "YES" << nl;
        return;
    }
    if(n == 2) {
        cout << "NO" << nl;
        return;
    }

    sort(all(arr));
    
    _vb visited(n, false);
    int cycles = 0;
    F0R(i, n) {
        if(!visited[i]) {
            cycles++;
            int curr = i;
            while(!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].sc;
            }
        }
    }

    if((n - cycles) % 2) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }



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


