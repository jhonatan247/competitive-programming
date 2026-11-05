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

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const char nl = '\n';

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = uid(1, 1);
    cout << t << nl;
    while(t--) {
        int n = uid(1, 32);
        int k = uid(1 , n);
        cout << n << " " << k << nl;

        F0R(i, n) {
            if(i) cout << ' ';
            int a = uid(1, 500);
            cout << a;
        }
        cout << nl;
    }

    return 0;
}

