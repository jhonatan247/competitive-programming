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

const char nl = '\n';

void solve() {
    int n, m;
    cin >> n >> m;
    
    string p, q;
    cin >> p >> q;
    

    vector<int> cnt(27, 0);
    F0R(i, sz(p)) {
        cnt[p[i] - 'a']++;
    }

    F0R(i, sz(q)) {
        cnt[q[i] - 'a']--;
    }


    F0R(i, sz(cnt)) {
        if(i == 's' - 'a' or i == 'i' - 'a' or i == 'x' - 'a') {
            if(cnt[i] != 1) {
                cout << "NO" << nl;
                return;
            }
        } else if(cnt[i] != 0) {
            cout << "NO" << nl;
            return;
        }
    }
     
    cout << "YES" << nl;
    
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


