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

void solve() {
    int t = uid(1, 10); 
    while(t--) {
        cout << "start" << endl;
        int a = uid(1, 1e9);

        char opt;
        cin >> opt;
        int cnt = 0;

        while(opt == '?') {
            if(cnt >= 60) {
                cout << "mistake" << endl;
                exit(1);
            }
            int x, y;
            cin >> x >> y;
            cnt ++;

            if(y % a > x % a) {
                cout << "y" << endl;
            } else {
                cout << "x" << endl;
            }
            cin >> opt;
        }
        int ans;
        cin >> ans;
        if(ans != a) {
            cout << "mistake" << endl;
            exit(1);
        }
    }
    cout << "end" << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;

    while(T--) {
        solve();
    }
     
    cout << "OK" << endl;

    return 0;
}


