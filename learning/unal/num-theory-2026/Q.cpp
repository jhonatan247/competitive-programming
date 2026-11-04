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

const int MX = 1e9;


template <typename T, typename F>
T first_true(T lo, T hi, F pred) {
    while (lo < hi) { T mid = lo + (hi - lo) / 2;
        if (pred(mid)) hi = mid; else lo = mid + 1; }
    return lo;
}
template <typename T, typename F>
T last_true(T lo, T hi, F pred) {
    while (lo < hi) { T mid = lo + (hi - lo) / 2;
        if (pred(mid)) lo = mid + 1; else hi = mid; }
    return lo - 1;
}

char ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    char ans;
    cin >> ans;
    return ans;
}

void answer(int a) {
    cout << "! " << a << endl;
}

void solve() {
    int x, y;

    x = 0; 
    y = 1;
    
    if(ask(x, y) == 'x') {
        answer(1);
        return;
    }

    x = 1;
    y = 2;

    while(ask(x, y) == 'y') {
        x = y;
        y = min(y * 2, MX);
    }

    int l = x + 1;
    int r = y;

    int ans = first_true(l, r, [&](int mid) {
        return ask(x, mid) == 'x';
    });

    answer(ans);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    while(s == "start") {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
        
        cin >> s;
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


