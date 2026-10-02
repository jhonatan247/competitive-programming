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
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> arr(m);
    F0R (i, m) {
        cin >> arr[i];
    }


    vector<pair<char, int>> ops;
    int i = 0;
   
    while(i < n){
        if(s[i] == 'B'){
            ops.pb(mp('B', 1));
            i++;
            continue;
        }
        int cnt = 0;
        while(i < n and s[i] == 'A'){
            cnt ++;
            i++;
        }
        ops.pb(mp('A', cnt));
   }

    if(sz(ops) == 1 and ops[0].fr == 'A'){
        TRAV(q, arr) {
            cout << q << nl;
        }
        return;
    }

    TRAV(q, arr) {
        int opIndx = 0;
        int cnt = 0;

        while(q != 0){
            auto curr = ops[opIndx];
            if(curr.fr == 'B'){
                q /= 2;
                cnt++;
            }else {
                if(q <= curr.sc){
                    cnt += q;
                    q = 0;
                    continue;
                }
                q -= curr.sc;
                cnt += curr.sc;
            }
            opIndx = (opIndx + 1) % sz(ops);
        }

        cout << cnt << nl;
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

