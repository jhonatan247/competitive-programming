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

const int MOD = 9302023;

// Mapping of words to digits
const string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Sets to keep track of visited states and all reachable states
unordered_set<string> visited;
unordered_set<string> reachable;

void dfs(const string& curr_s) {
    // If we have already processed this string, stop
    if (visited.count(curr_s)) {
        return;
    }
    
    // Mark as visited and add to reachable set
    visited.insert(curr_s);
    reachable.insert(curr_s);

    // Try replacing every possible word at every possible position
    for (int i = 0; i < 10; ++i) {
        const string& word = words[i];
        char digit = digits[i];
        
        size_t start = 0;
        size_t pos = curr_s.find(word, start);
        
        while (pos != string::npos) {
            // Create the new string by replacing the word with the digit
            string next_s = curr_s.substr(0, pos) + digit + curr_s.substr(pos + word.length());
            
            // Recurse
            dfs(next_s);
            
            // Move past this occurrence to find overlapping matches (e.g., "twone")
            pos = curr_s.find(word, pos + 1);
        }
    }
}

void solve() {
    visited = {};
    reachable = {};
    string S;
    if (!(cin >> S)) return;

    // Run brute-force DFS
    dfs(S);

    // Find the minimum length among all reachable strings
    if (reachable.empty()) {
        cout << 0 << "\n" << 0 << "\n";
        return;
    }

    size_t min_len = 1000005; // Safe upper bound based on constraints
    for (const string& s : reachable) {
        if (s.length() < min_len) {
            min_len = s.length();
        }
    }

    // Count how many distinct strings have this minimum length
    long long count = 0;
    for (const string& s : reachable) {
        if (s.length() == min_len) {
            count++;
        }
    }

    // Output the result
    cout << min_len << "\n";
    cout << count % MOD << "\n";
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

