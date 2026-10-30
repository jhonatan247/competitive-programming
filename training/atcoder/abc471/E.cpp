#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include "algo/modular.h"

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

const _ll MOD = 998244353;

using Mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

const _ll MX = 200001;

Mint fact[MX];
Mint inv_fact[MX];

Mint mod_inverse(Mint n) {
    return power(n, MOD -2);
}

void mod_factorial(Mint n) {
    fact[0] = 1;
    inv_fact[0] = 1;
    for(Mint i = 1; i < n; i++) {
        fact[i()] = fact[i() - 1] * i;
    }

    inv_fact[n() - 1] = mod_inverse(fact[n() - 1]);
    for(Mint i = n - 2; i() >= 1; i--) {
        inv_fact[i()] = inv_fact[i() + 1] * (i + 1);
    }

}

Mint nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] * inv_fact[n - r];
}


void solve() {
    int n, k;
    cin >> n >> k;
    
    Mint s1, s2;
    F0R(i, n) {
        Mint a;
        cin >> a;
        s1 += a;
        s2 += a * a;
    }

    Mint c1 = nCr(n - 1, k - 1);
    Mint c2 = nCr(n - 2, k - 2);

    Mint cross = s1 * s1 - s2;

    Mint ans = c1 * s2 + c2 * cross;

    cout << ans() << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    mod_factorial(MX);
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


