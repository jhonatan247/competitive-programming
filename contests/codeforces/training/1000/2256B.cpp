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

const _ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;


    int firstI = -1;
    F0R(i, n) {
        if(s[i] != '?'){
            firstI = i; break;
        }
    }

    if(firstI == -1){
        cout << 4 << nl;
        return;
    }
    
    map<char, char> eq;
    eq['1'] = '1';
    eq['0'] = '0';
    map<char, char> dff;
    dff['0'] = '1';
    dff['1'] = '0';

    string s2 = s;
    
    int l = firstI - 1;
    int r = firstI + 1;
    
    char nextL1 = eq[s[firstI]];
    bool nextL1eq = s[firstI] == nextL1;
    char nextL2 = dff[s[firstI]];
    bool nextL2eq = s[firstI] == nextL2;
    char nextR1 = eq[s[firstI]];
    bool nextR1eq = s[firstI] == nextR1;
    char nextR2 = dff[s[firstI]];
    bool nextR2eq = s[firstI] == nextR2;

    bool valid1 = true;
    bool valid2 = true;
    
    while(l > 0){
        if(valid1 && s[l] != '?' && s[l] != nextL1){
            valid1 = false;
        }
        if(valid2 && s[l] != '?' && s[l] != nextL2){
            valid2 = false;
        }
        if(valid1){
            if(nextL1eq){
                nextL1 = dff[nextL1];
            }else {
                nextL1 = eq[nextL1];
            }
            nextL1eq = !nextL1eq;
        }

        if(valid2){
            if(nextL2eq){
                nextL2 = dff[nextL2];
            }else {
                nextL2 = eq[nextL2];
            }
            nextL2eq = !nextL2eq;
            
        }
        if(!valid1 and !valid2) break;
        l--;
    }
    
    while(r < n){
        if(valid1 && s[r] != '?' && s[r] != nextR1){
            valid1 = false;
        }
        if(valid2 && s[r] != '?' && s[r] != nextR2){
            valid2 = false;
        }
        if(valid1){
            if(nextR1eq){
                nextR1 = dff[nextR1];
            }else {
                nextR1 = eq[nextR1];
            }
            nextR1eq = !nextR1eq;
        }

        if(valid2){
            if(nextR2eq){
                nextR2 = dff[nextR2];
            }else {
                nextR2 = eq[nextR2];
            }
            nextR2eq = !nextR2eq;
        }
        if(!valid1 and !valid2) break;
        r++;
    }

    if(valid1 and valid2){
        cout << 2 << nl;
    } else if ( valid1 or valid2) {
        cout << 1 << nl;
    } else {
        cout << 0 << nl;
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

