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
#ifdef LOCAL
template<class T, class... Ts>
void debug_out(const T& x, const Ts&... xs);
#define debug(...) do { \
    cerr << "@@@ " << #__VA_ARGS__ << " ="; \
    debug_out(__VA_ARGS__); \
    cerr << nl; \
} while (0)
#else
#define debug(...) ((void)0)
#endif

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
    cin>>s;
    
    vector<int> missings;
    for(int digits=1; digits <= min(5, sz(s)); digits++){
        if(sz(s) % digits != 0) continue;
        string firstNumber="";
        for(int j=0;j<digits;j++){
            firstNumber += s[j];
        }
        int start = stoi(firstNumber);
        int next= start+1;
        string snext= to_string(next);
        int missing = -1;
        bool success = true;
        int position = digits;
        if(sz(firstNumber) != sz(s))
        {     
           while(true){
                if(position + sz(snext) > sz(s)){
                    success = false;
                    break;
                }
                bool isEqual=true;
                for(int j=0; j < sz(snext); j++){
                    if(snext[j] != s[position+j]){
                        isEqual=false;
                        break;
                    }
                }
                if(!isEqual && missing == -1){
                    missing = next;
                }
                else if(!isEqual){
                    missing = -1;
                    success = false;
                    break;
                }else{
                    position += sz(snext);
                }

                next += 1;
                snext=to_string(next);
                if(position == sz(s) && isEqual){
                    break;
                }
            }
        }

        if(success){
            if(missing != -1){
                missings.pb(missing);
            }else{
                if(start - 1 > 0)
                    missings.pb(start - 1);
                if(next <= 99999)
                    missings.pb(next);
            }
        }
    }
    sort(all(missings));
    cout << sz(missings);
    if(sz(missings)){
        cout << nl;
    }
    for(auto it: missings){
        cout << it << ' ';
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

