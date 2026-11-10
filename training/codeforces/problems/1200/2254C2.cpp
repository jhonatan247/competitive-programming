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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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

_ll min_swaps(_vb &a, _vb &b) {
   pqg<_ll> ones;
   pqg<_ll> zeroes;

   F0R(i, sz(a)) {
       if(a[i]) {
           ones.push(i);
       } else {
           zeroes.push(i);
       }
   }
    
   _ll swaps = 0;
   F0R(i, sz(b)) {
       if(b[i]) {
           if(ones.top() != i) {
               swaps += ones.top() - i;
               zeroes.pop();
               zeroes.push(ones.top());
           }
           ones.pop();
       } else {
           if(zeroes.top() != i) {
               swaps += zeroes.top() - i;
               ones.pop();
               ones.push(zeroes.top());
           }
           zeroes.pop();
       }
   }

   return swaps;
}

void solve() {
    int n;
    cin >> n;
    
    string a;
    cin >> a;
    string b;
    cin >> b;
    
    _vb a_even;
    int a_cnt_even = 0;
    _vb b_even;
    int b_cnt_even = 0;
    
    _vb a_odd;
    int a_cnt_odd = 0;
    _vb b_odd;
    int b_cnt_odd = 0;

    F0R(i, n) {
        if(i % 2) {
            a_odd.pb(a[i] == '1');
            a_cnt_odd += a_odd.back();
            b_odd.pb(b[i] == '1');
            b_cnt_odd += b_odd.back();
        } else {
            a_even.pb(a[i] == '1');
            a_cnt_even += a_even.back();
            b_even.pb(b[i] == '1');
            b_cnt_even += b_even.back();
        }
    }

    if(a_cnt_odd != b_cnt_odd or a_cnt_even != b_cnt_even) {
        cout << -1 << nl;
        return;
    }

    _ll ans = min_swaps(a_even, b_even) + min_swaps(a_odd, b_odd);
    cout << ans << nl;
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


