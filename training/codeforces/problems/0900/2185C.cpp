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

#define F0R(i, a) for (int i=0; i<(a); i++)

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
    
    sort(all(arr));

    int cnt = 0;
    int prev = INT_MIN;
    int max_cnt = 0;
    F0R(i, n + 1) {
        if(i < n and arr[i] <= prev + 1) {
            if(arr[i] == prev + 1) cnt++;
        } else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
        if(i < n) prev = arr[i];
    }
    cout << max_cnt << nl;
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


