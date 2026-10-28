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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define fill0(a) memset(a, 0, sizeof a)
#define fill(a, v) memset(a, v, sizeof a)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    queue<pair<bool, int>> bottom;
    pqg<pair<bool, int>> top;
    F0R(i, n) {
        bool isNormalCard = i != p - 1;
        if(i < k) {
            top.push(mp(isNormalCard, arr[i]));
        } else {
            bottom.push(mp(isNormalCard, arr[i]));
        }
    }

    int ans = 0;
    int currCost = 0;
    while(currCost < m) {
        auto curr = top.top();
        top.pop();
        currCost += curr.sc;
        if(!curr.fr and currCost <= m) {
            ans++;
        }
        bottom.push(curr);
        top.push(bottom.front());
        bottom.pop();
    }
    cout << ans << nl;
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


