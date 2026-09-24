#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#pragma GCC optimize ("O3")

#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif 

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long _ll;
typedef long double _ld;
 
#define F0R(i, a) for (int i=0; i<(a); i++)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<_ll> a(n);
    for (_ll &x : a) cin >> x;

    priority_queue<_ll> pq;
    _ll sum = 0, ans = LLONG_MIN;

    for (int i = 0; i < n; ++i) {
        if ((int)pq.size() == m - 1) {
            ans = max(ans, m * a[i] - sum);
        }

        pq.push(a[i]);
        sum += a[i];
        if ((int)pq.size() == m) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}

