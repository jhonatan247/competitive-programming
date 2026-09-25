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

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    vector<string> words = {
        "a",
        "b",
        "c",
        "d",
        "e",
        "zero",
        "zerone",
        "zeroneight",
        "zeroneighthree",
        "one",
        "oneight",
        "oneighthree",
        "oneighthreeight",
        "two",
        "twone",
        "twoneight",
        "twoneighthree"
        "twoneighthreeight",
        "three",
        "threeight",
        "threeighthree",
        "four",
        "five",
        "fiveight",
        "fiveighthree",
        "fiveightthreeignt",
        "six",
        "seven",
        "sevenine",
        "sevenineight",
        "sevenineighthree",
        "sevenineighthreeight",
        "eight",
        "eighthree",
        "eighthreeight",
        "eighthreeighthree",
        "nine",
        "nineight",
        "nineighthree",
        "nineighthreeight",
        "nineighthreeighthree"
    };

    int nw = uid(1, 3);
    string output = "";
    F0R(i, nw) {
        if(sz(output)){
            bool removeLast = uid(0, 1);
            if(removeLast) output.pop_back();
        }

        int sel = uid(0, sz(words) - 1);
        output += words[sel];
    }
    cout << output << endl;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;
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

