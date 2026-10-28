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

bool verify(string s) {
    bool found = false;
    F0R(i, sz(s)) {
        if(s[i] == '1') {
            found = true;
        } else if(found) {
            return false;
        }
    }
    return true;
}

int compute(string s) {
    if(verify(s)) return 0;
    string a = s;
    string b = s;
    auto first = a.find_first_of('1');
    a.erase(first, 1);
    auto last = b.find_last_of('2');
    b.erase(last, 1);
    return 1 + min(compute(a), compute(b));
}


void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    s.erase(remove(all(s), '4'), s.end());
    replace(all(s), '3', '1');
    int ans = n - sz(s) + compute(s);
    cout << ans << nl;
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


