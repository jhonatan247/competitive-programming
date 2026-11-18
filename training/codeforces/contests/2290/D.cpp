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

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)
#define P_TRAV(k, a, x) for (auto& [k, a] : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    _vi EQ(27);
    F0R(i, sz(EQ)) {
        EQ[i] = (int)i;
    }

    auto get_eq = [&](char c) {
        return EQ[c - 'a'];
    };
    
    auto is_palindrome = [&](char c) {
        int l = 0;
        int r = n - 1;
        int eq_c = get_eq(c);
        while(l < r) {
            int eq_l = get_eq(s[l]);
            int eq_r = get_eq(s[r]);
            if((eq_l == eq_c or eq_r == eq_c) and eq_r != eq_l) return false;
            l++;
            r--;
        }
        return true;
    };


    int ops = 0;
    
    for(char i = 'z'; i > 'a'; i--) {
        if(!is_palindrome(i)) {
            FOR(j, i, 'z' + 1) {
                EQ[j - 'a']--;
            }
            ops++;
        }
    }
    cout << ops << nl;
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


