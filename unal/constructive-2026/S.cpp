#ifdef LOCAL
    #define _GLIBCXX_DEBUG
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
    _ll n, k;
    cin >> n >> k;
    
    if(k < (n * (n + 1)) / 2) {
        cout << -1 << nl;
        return;
    }

    vector<int> p(n);
    vector<int> q(n);
    F0R(i, n) {
        p[i] = i + 1;
        q[i] = i + 1;
    }

    int l = 0;
    int r = n - 1;
    _ll sum = (n * (n + 1)) / 2;

    while(l < r and sum < k) {
        _ll miss = k - sum;
        if(miss >= r - l) {
            swap(q[l], q[r]);
            sum += r - l;
            r--;
            l++;
        } else {
            swap(q[l], q[l + miss]);
            sum += miss;
            break;
        }
    }
    cout << sum << nl;
    F0R(i, n) {
        if(i) cout << ' ';
        cout << p[i];
    }
    cout << nl;
    F0R(i, n) {
        if(i) cout << ' ';
        cout << q[i];
    }
    cout << nl;

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


