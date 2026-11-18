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

#define nl endl
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n = uid(2, 1000);
    cout << n << nl;

    int c;
    cin >> c;

    if(n <= 4 && c > 2) {
        exit(0);
    }
    
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    int q = uid(1, 10);
    cout << q << nl;

    bool error = false;

    while(q--) {
        int m = uid(2 * n, 3 * n);
        cout << m;

        _vi pth;
        int i = uid(0, n - 1);
        bool incr = true;
        bool rand = false;
        F0R(j, m) {
            cout << ' ' << arr[i];
            pth.push_back(i + 1);
            if(i == n - 1) {
                i--;
                incr = false;
            }
            else if(i == 0) {
                i++;
                if(!incr) rand = false;
                incr = true;
             
            }
            else {
                bool opt = uid(0, 1);
                if((!rand and incr) or (rand and opt)) {
                    i++;
                } else {
                    i--;
                }
            }
        }
        cout << nl;

        vector<int> ans(m);
        F0R(j, m) {
            cin >> ans[j];
        }
        
        if(ans != pth) {
            debug(pth);
            exit(-1);
            error = true;
        }


    }
    if(!error)
        cout << "OK" << nl;
    return 0;
}

