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
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

typedef vector<_vi> _vvi;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl; 

#define F0R(i, a) for (int i=0; i<(a); i++)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
const int MOD = 9302023;
// A large number to represent an unreachable state
const int INF = 1e9; 

// All possible number words we can replace
const vector<string> NUMBER_WORDS = {
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // min_len[i] = minimum length of the resulting string using the prefix s[0...i-1]
    // ways[i]    = number of distinct strings that achieve min_len[i] (modulo MOD)
    vector<int> min_len(n + 1, INF);
    vector<int> ways(n + 1, 0);
    
    // Base Case: An empty prefix requires 0 length and has exactly 1 way (doing nothing)
    min_len[0] = 0;
    ways[0] = 1;
    
    // Process the string from left to right
    for (int i = 1; i <= n; ++i) {
        
        // --- Option 1: Keep the current character as a single letter ---
        // We simply append s[i-1] to the optimal result of the previous prefix.
        min_len[i] = min_len[i-1] + 1;
        ways[i] = ways[i-1];
        
        // --- Option 2: Replace a valid word ending at position i with a digit ---
        for (const string& word : NUMBER_WORDS) {
            int word_len = word.length();
            
            // Check if the string ends with this word
            // s.compare(start_index, length, target_string)
            if (i >= word_len && s.compare(i - word_len, word_len, word) == 0) {
                
                int prev_len = min_len[i - word_len];
                int prev_ways = ways[i - word_len];
                
                // If we replace this word, the length becomes: (prefix length) + 1 (for the digit)
                int candidate_len = prev_len + 1;
                
                if (candidate_len < min_len[i]) {
                    // We found a strictly shorter string!
                    // Update the minimum length and reset the ways to match this new path.
                    min_len[i] = candidate_len;
                    ways[i] = prev_ways;
                } 
                else if (candidate_len == min_len[i]) {
                    // We found another distinct way to achieve the same minimum length.
                    // Add the number of ways from this path to our total.
                    ways[i] = (ways[i] + prev_ways) % MOD;
                }
            }
        }
    }
    
    // Output the results for the entire string
    cout << min_len[n] << "\n";
    cout << ways[n] << "\n";
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

