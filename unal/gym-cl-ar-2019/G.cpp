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
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n - 1);
 
    int arr0;
    cin >> arr0;
    
    for(int i = 0; i < n - 1; i ++){
        cin >> arr[i];
    }
 
    sort(all(arr));
 
    int i = 0;
    while(i < n - 1 and arr0 > 0) {
        int curr = arr[i];
        if(i == 0)
            arr0 -= (curr - 1) * (n - 1 - i);
        else
            arr0 -= (curr) * (n - 1 - i);
        i++;
    }
    if(arr0 > 0) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


