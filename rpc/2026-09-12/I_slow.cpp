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
    string s;
    cin >> s;
    vector<int> missings;
    int n = s.size();
    
    for (int digits = 1; digits <= min(5, n); digits++) {
        string firstNumber = s.substr(0, digits);
        int start = stoi(firstNumber);
        int next = start + 1;
        string snext = to_string(next);
        int missing = -1;
        bool success = true;
        int position = digits;
        
        while (position < n) {
            if (position + (int)snext.size() > n) {
                success = false;
                break;
            }
            bool isEqual = true;
            for (int j = 0; j < (int)snext.size(); j++) {
                if (s[position + j] != snext[j]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                position += snext.size();
                next++;
                snext = to_string(next);
            } else {
                if (missing == -1) {
                    missing = next;
                    next++;
                    snext = to_string(next);
                    // position unchanged
                } else {
                    success = false;
                    break;
                }
            }
        }
        
        if (success) {
            if (missing != -1) {
                missings.push_back(missing);
            } else {
                if (start - 1 >= 1) missings.push_back(start - 1);
                if (next <= 99999) missings.push_back(next);
            }
        }
    }
    
    sort(missings.begin(), missings.end());
    missings.erase(unique(missings.begin(), missings.end()), missings.end());
    
    cout << missings.size() << '\n';
    for (int i = 0; i < (int)missings.size(); i++) {
        if (i) cout << ' ';
        cout << missings[i];
    }
    cout << '\n';
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

