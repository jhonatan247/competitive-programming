#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
const char SCAN = '1';
const char MEMORY = '2';
const char QUICK = '3';


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<bool> printed(n + 1, false);
    stack<int> memory;
    int count = 0;
    
    F0R(i, n) {
        if(s[i] == SCAN) {
            memory.push(i + 1);
        } else if(s[i] == MEMORY) {
            if(memory.empty()) {
                printed[i + 1] = true;
            } else {
                printed[memory.top()] = true;
                memory.pop();
            }
            count++;
        } else {
            printed[i + 1] = true;
            count++;
        }
    }

    cout << n - count << nl;
    int pCount = 0;
    FOR(i, 1, n + 1) {
        if(!printed[i]) {
            if(pCount) cout << ' ';
            cout << i;
            pCount ++;
        }
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


