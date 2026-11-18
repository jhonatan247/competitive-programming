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

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    sort(all(arr), greater<int>());

    deque<int> ans;
    F0R(i, n) {
        if(i % 2) {
            ans.emplace_back(arr[i]);
        } else {
            ans.emplace_front(arr[i]);
        }
    }
    int cnt = 0;
    F0R(i, n) {
        if(i == 0 or i == n - 1) cnt++;
        else if(ans[i - 1] < ans[i] or ans[i + 1] < ans[i]) cnt++;
    }
    
    cout << cnt << nl;
    F0R(i, n) {
       if(i) cout << ' ';
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


