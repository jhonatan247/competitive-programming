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
    int n;
    cin>>n;
    int zCnt = 0;
    vector<int> arr(n);
    int firstZi = -1;
    F0R(i, n) {
        cin>>arr[i];
        if(arr[i] == 0){
            zCnt ++;
            if(firstZi == -1) firstZi = i;
        }
    }
    if(zCnt == 0){
        string zout(n, 'A');
        cout << "YES" << nl;
        cout << zout << nl;
    }
    if(zCnt == 1) cout << "NO" << endl;

    if(zCnt > 1){
        cout << "YES" << endl;
        F0R(i, n) {
            if(i == firstZi){
                cout << 'A';          
            }else if (arr[i] == 0) cout << 'B';
            else cout << 'C';
        }
        cout <<endl;
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

