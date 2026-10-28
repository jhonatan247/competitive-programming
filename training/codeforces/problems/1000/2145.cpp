#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "local/debug.h"
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    sort(all(s));

    vector<char> ans(n, '+');
    int cnt = 0;
    F0R(i, k) {
        if(s[i] == '2') cnt++;
    }

    int l = 0;
    int r = n - 1;
    debug(cnt);
    bool firstS = true;
    F0R(i, k) {
        if(l > r or ans[l] != '+' or ans[r] != '+') break;
        if(s[i] == '0') {
            ans[l] = '-';
            l++;
        } else if (s[i] == '1') {
            ans[r] = '-';
            r--;
        } else if(firstS && cnt >= r - l + 1) {
            FOR(j, l, r + 1) {
                ans[j] = '-';
            }
            break;
        } else {
            ans[l] = '?';
            ans[r] = '?';
            l++;
            r--;
            firstS = false;
        }
        debug(ans);
    }

    F0R(i, n) {
        cout << ans[i];
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
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


