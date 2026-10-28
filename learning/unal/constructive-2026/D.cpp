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
    vector<int> arr(n);
    int pos1 = -1;
    int pos2 = -1;
    int posN = -1;
    F0R (i, n) {
        cin >> arr[i];
        if(arr[i] == 1) pos1 = i + 1;
        if(arr[i] == 2) pos2 = i + 1;
        if(arr[i] == n) posN = i + 1;
    }
    int aux = pos1;
    pos1 = min(pos1, pos2);
    pos2 = max(aux, pos2);

    if(n <= 2 or (pos1 < posN and posN < pos2)  ) {
        cout << pos1 << ' ' << pos1 << nl;
        return;
    }
    
    if(posN < pos1) {
        cout << posN << ' ' << pos1 << nl;
    } else {
        cout << posN << ' ' << pos2 << nl;
    }
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


