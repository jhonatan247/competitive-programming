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
    int n, k;
    cin >> n >> k;

    string s = "";
    F0R(i, n) {
        if(i) s+= ' ';  
        string word;
        cin >> word;
        s += word;
    } 

    vector<int> fr(26, 0);

    int c = 0;

    F0R(i, sz(s)) {
        if(s[i] == ' ') continue;
        int next = (s[i] - 'a' - c) % 26;
        if(next < 0) next += 26;
        fr[next]++;
        if(fr[next] % k == 0) c++;
        s[i] = 'a' + next;
    }
    cout << s << nl;
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

