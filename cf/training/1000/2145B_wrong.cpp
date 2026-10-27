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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<char> ans(n, '+');
    int l = 0;
    int r = n - 1;
    debug(s);
    F0R(i, k) {
        if(s[i] == '0') {
            if(l == 0 or ans[l - 1] == '-') {
                if(ans[l] == '?' and l < n - 1 and ans[l + 1] == '?') {
                    ans[l + 1] = '-';
                    l++;
                }
                ans[l] = '-';
            } else {
                ans[l] = '?';
                int j = l - 1;
                while(j >= 0 and ans[j] == '?') {
                    j--;
                }
                j++;
                if(j != l) ans[j] = '-';
            }
            l++;
        } else if(s[i] == '1') {
            if(r == n - 1 or ans[r + 1] == '-') {
                if(ans[r] == '?' and r > 0 and ans[r - 1] == '?') {
                    ans[r - 1] = '-';
                    r--;
                }
                ans[r] = '-';
            } else {
                ans[r] = '?';
                int j = r + 1;
                while(j < n and ans[j] == '?') {
                    j++;
                }
                j--;
                if(j != r) ans[j] = '-';
            }
            r--;
        } else {
            if(l == r and (l == 0 or ans[l - 1] == '-') and (r == n - 1 or ans[r + 1] == '-')) {
                ans[l] = '-';
            } else {
                ans[l] = '?';
                ans[r] = '?';
            }
            l++;
            r--;
        }
        if(l == n) l = n - 1;
        if(r < 0) r = 0;
        debug(ans);
    }

    F0R(i, n) {
        cout << ans[i];
    }
    cout <<nl;
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


