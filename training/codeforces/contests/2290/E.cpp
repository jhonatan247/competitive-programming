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
typedef __int128_t _i128;

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
    _ll n, k;
    cin >> n >> k;
    
    vector<_ll> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    _ll sum = 0;
    
    deque<_ll> accum;
    accum.push_back(0);

    F0Rd(i, n) {
        _ll new_accum = accum.back() + arr[i];

        if(sz(accum) > k) {
            new_accum -= accum.front();
            accum.pop_front();
        }


        sum += (new_accum) % 2;
        accum.push_back((new_accum + accum.back()) % 2); 
    }
    

    if(sum % 2 == 0) {
        cout << "Bob" << nl;
    } else {
        cout << "Alice" << nl;
    }

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


