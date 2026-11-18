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

#define F0R(i, a) for (int i=0; i<(a); i++)

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
    
    vector<int> arr(2 * n);
    _vi zeroes;
    F0R(i, sz(arr)) {
        cin >> arr[i];
        if(arr[i] == 0) {
            zeroes.pb(i);
        }
    }
    
    debug(zeroes);

    auto is_palindrome = [&](int l, int r) {
        while(l < r) {
            if(arr[l] != arr[r]) return false;
            l ++; r--;
        }
        return true;
    };

    auto palindromex = [&](int l, int r) {
        _vb visited(n, false);
        while(l >= 0 and r < sz(arr) and arr[l] == arr[r]) {
            visited[arr[l]] = true;
            l--; 
            r++;
        }

        F0R(i, n) {
            if(!visited[i]) return i;
        }
        return n;
    };
    

    int mex = 0;
    if(is_palindrome(zeroes[0], zeroes[1])) {
        int l = (zeroes[1] - zeroes[0]) / 2 + zeroes[0];
        int r = (zeroes[1] - zeroes[0]) % 2 ? l + 1 : l;
        debug(l, r);
        mex = palindromex(l , r);
    }

    mex = max({mex, palindromex(zeroes[0], zeroes[0]), palindromex(zeroes[1], zeroes[1])});
    cout << mex << nl;


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


