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

#define nl endl
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = uid(1, 2);
    
    cout << t << nl;

    while(t--) {
       _ll x = uid(1, 100);
       debug(x);
       int cnt = 0;
       char q;
       cin >> q;
       while(q == '?') {
           if(cnt >= 30) {
               exit(1);
           }
           
           _ll a, b;
           cin >> a >> b;
           cnt++;

           cout << gcd(a + x, b + x) << endl;

           cin >> q;
       }

       _ll ans;
       cin >> ans;

       if(ans != x) {
           exit(1);
       }
    }

    cout << "OK" << nl;
    return 0;
}

