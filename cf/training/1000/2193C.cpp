#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef long double _ld;

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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<_ll> a(n);
    F0R (i, n) {
        cin >> a[i];
    }
    
    vector<_ll> b(n);
    F0R (i, n) {
        cin >> b[i];
    }
    
    a[n - 1] = max(a[n - 1], b[n - 1]);
    F0Rd(i, n - 1) {
        a[i] = max({a[i], a[i + 1], b[i]});
    }

    vector<_ll> psum(n, 0);
    psum[0] = a[0];
    FOR(i, 1, n) {
        psum[i] = psum[i - 1] + a[i];
    }

    F0R(i, q) {
        if(i) cout << ' ';

        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l > 0) {
            cout << psum[r] - psum[l - 1];
        }
        else {
            cout << psum[r];
        }
    }
    cout << nl;

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


