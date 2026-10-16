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
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

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

_vl primes;

bool is_prime(_ll n) {
    TRAV(prime, primes) {
        if(prime * prime > n) break;
        if(n % prime == 0) return false;
    }
    return true;
}

void find_primes() {
    primes.pb(2);
    while(sz(primes) < 100) {
        _ll curr = primes.back() + 1;
        while(!is_prime(curr)) {
            curr++;
        }
        primes.pb(curr);
    }
}

void solve() {
    int n;
    cin >> n;
    
    vector<_ll> arr(n);
    F0R (i, n) {
        cin >> arr[i];
    }
    
    TRAV(prime, primes) {
        F0R(i, n) {
            if(arr[i] < prime or arr[i] % prime != 0) {
                cout << prime << nl;
                return;
            }
        }
    }
    cout << -1 << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    find_primes();

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


