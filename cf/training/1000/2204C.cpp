#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 

void solve() {
    _ll a, b, c;
    cin >> a >> b >> c;
    _ll m;
    cin >> m;
    
    _ll ab = lcm(a, b);
    _ll ac = lcm(a, c);
    _ll bc = lcm(b, c);
    _ll abc = lcm(lcm(a, b), c);

    _ll _Ta = m / a;
    _ll _Tb = m / b;
    _ll _Tc = m / c;
    _ll Tall = m / abc;
    _ll Tab = m / ab - Tall;
    _ll Tac = m / ac - Tall;
    _ll Tbc = m / bc - Tall;

    _ll Ta = (_Ta - Tall - Tab - Tac) * 6 + Tab * 3 + Tac * 3 + Tall * 2;
    _ll Tb = (_Tb - Tall - Tab - Tbc) * 6 + Tab * 3 + Tbc * 3 + Tall * 2;
    _ll Tc = (_Tc - Tall - Tac - Tbc) * 6 + Tac * 3 + Tbc * 3 + Tall * 2;

    cout << Ta << ' ' << Tb << ' ' << Tc << nl;
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


