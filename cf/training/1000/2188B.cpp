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
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    if(n == 1) {
        cout << 1 << nl;
        return;
    }
    
    int cnt = 0;
    bool prev = 0;
    bool prevprev = 1;
    F0R(i, n) {
        bool curr = s[i] == '1';
        if(!prev and !prevprev and !curr or !prev and !curr and i == n - 1) {
            prevprev = prev;
            prev = 1;
            cnt++;
            continue;
        }
        if(curr) cnt++;
        prevprev = prev;
        prev = curr;
    }
    cout << cnt << nl;
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


