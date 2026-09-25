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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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
const int MOD = 9302023;
 
void solve() {
    string s;

    cin >> s;

    int n = sz(s);

    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    unordered_map<string,string> preferredSuffixes;
    preferredSuffixes["one"] = "eight";
    preferredSuffixes["nine"] = "eight";
    preferredSuffixes["five"] = "eight";

    unordered_map<string,string> unPreferredSuffixes;
    unPreferredSuffixes["zero"] = "one";
    unPreferredSuffixes["seven"] = "nine";
    
    unordered_map<string,string> siblings;
    siblings["eight"] = "three";
    siblings["three"] = "eight";

    unordered_map<string,string> halfSiblings;
    halfSiblings["two"] = "one";


    pqg<pair<int,string>> foundNums;

    TRAV(num, nums) {
        int i = 0;
        while(i < n){
            if(s[i] == num[0] and i + sz(num) <= n){
                bool isEqual = true;
                FOR(j, 1, sz(num)) {
                    isEqual = num[j] == s[i + j];
                    if(!isEqual) break;
                }
                if(isEqual){
                    foundNums.push(mp(i, num));
                    i += sz(num);
                    continue;
                }
            }
            i++;
        }
    }
    int minsz = n;
    int combinations = 1;

    while(!foundNums.empty()){
        debug(combinations, minsz, foundNums);
        pair<int,string> curr = foundNums.top();
        foundNums.pop();
        int indx = curr.fr;
        string num = curr.sc;
        if(foundNums.empty()){
            minsz -= sz(num) - 1;
            break;
        }

        pair<int, string> next = foundNums.top();
        int nextIndx = next.fr;
        string nextNum = next.sc;

        if(preferredSuffixes.count(num)){
            if(nextNum == preferredSuffixes[num]){
                if(indx + sz(num) > nextIndx){
                    if(sz(foundNums) == 1) continue;
                    string prevNum = num;
                    curr = next;
                    foundNums.pop();
                    indx = curr.fr;
                    num = curr.sc;
                    next = foundNums.top();
                    nextIndx = next.fr;
                    nextNum = next.sc;
                    if(nextNum == siblings[num] && (indx + sz(num) > nextIndx)){
                        debug("===enter===");
                        minsz -= sz(prevNum) - 1;
                    }else{
                        foundNums.push(curr);
                    }
                    continue;
                }
            }
            minsz -= sz(num) - 1;
        }
        else if(unPreferredSuffixes.count(num)){
            if(nextNum == unPreferredSuffixes[num]){
                if(indx + sz(num) > nextIndx){
                    foundNums.pop();
                }
            }
            minsz -= sz(num) - 1;
        }
        else if(siblings.count(num)){
            int count = 1;
            int aCount = 1;
            int bCount = 0;
            
            while(nextNum == siblings[num] && (indx + sz(num) > nextIndx)){
                if(count % 2 == 0){
                    aCount++;
                }else {
                    bCount++;
                }
                count++;
                curr = next;
                foundNums.pop();
                indx = curr.fr;
                num = curr.sc;
                if(foundNums.empty()) break;
                next = foundNums.top();
                nextIndx = next.fr;
                nextNum = next.sc;
            }
            if(count % 2 == 0){
                combinations = (combinations * 2) % MOD;
            }
            minsz -= (sz(num) - 1) * aCount;
        }else if(num == "two"){
            if(nextNum == "one" and (indx + sz(num) > nextIndx)){
                curr = next;
                foundNums.pop();
                indx = curr.fr;
                num = curr.sc;
                if(foundNums.empty()){
                    combinations = (combinations * 2) % MOD;
                    minsz -= 2;
                    continue;
                }
                next = foundNums.top();
                nextIndx = next.fr;
                nextNum = next.sc;
                if(siblings.count(nextNum) && (indx + sz(num) > nextIndx)){
                    curr = next;
                    foundNums.pop();
                    indx = curr.fr;
                    num = curr.sc;
                    next = foundNums.top();
                    nextIndx = next.fr;
                    nextNum = next.sc;

                    int count = 1;
                    int aCount = 1;
                    int bCount = 0;
                    
                    while(nextNum == siblings[num] && (indx + sz(num) > nextIndx)){
                        if(count % 2 == 0){
                            aCount++;
                        }else {
                            bCount++;
                        }
                        count++;
                        curr = next;
                        foundNums.pop();
                        indx = curr.fr;
                        num = curr.sc;
                        if(foundNums.empty()) break;
                        next = foundNums.top();
                        nextIndx = next.fr;
                        nextNum = next.sc;
                    }
                    if(count % 2 == 0){
                        combinations = (combinations * 2) % MOD;
                    }
                    minsz -= (sz(num) - 1) * aCount + 2;
                }else{
                    debug("===ENTER2===");
                    combinations = (combinations * 2) % MOD;
                    minsz -= 2;
                }
            }else{
                minsz -= 2;
            } 
        }else{
            minsz -= sz(num) - 1;
        }
    }
    cout << minsz << nl;
    cout << combinations << nl;
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

#ifdef LOCAL
    template<class T>
    void debug_print(const T& x);
    void debug_print(const string& s) { cerr << quoted(s); }
    void debug_print(string_view s) { cerr << quoted(s); }
    void debug_print(const char* s) {
        if (s) cerr << quoted(s);
        else   cerr << "nullptr";
    }
    void debug_print(char* s) { debug_print((const char*)s); }
    template<size_t N>
    void debug_print(const char (&s)[N]) { cerr << quoted(s); }
    template<class A, class B>
    void debug_print(const pair<A, B>& p) {
        cerr << '(';
        debug_print(p.first);
        cerr << ", ";
        debug_print(p.second);
        cerr << ')';
    }
    template<class... Ts>
    void debug_print(const tuple<Ts...>& t) {
        cerr << '(';
        apply([&](const auto&... xs) {
            bool first = true;
            ((cerr << (first ? "" : ", "), first = false, debug_print(xs)), ...);
        }, t);
        cerr << ')';
    }
    void debug_print(const vector<bool>& v) {
        cerr << '{';
        bool first = true;
        for (bool x : v) {
            if (!first) cerr << ", ";
            first = false;
            debug_print(x);
        }
        cerr << '}';
    }
    template<class T, class C>
    void debug_print(const queue<T, C>& q0) {
        auto q = q0;
        vector<T> v;
        while (!q.empty()) v.push_back(q.front()), q.pop();
        debug_print(v);
    }
    template<class T, class C>
    void debug_print(const stack<T, C>& s0) {
        auto s = s0;
        vector<T> v;
        while (!s.empty()) v.push_back(s.top()), s.pop();
        debug_print(v);
    }
    template<class T, class C, class Comp>
    void debug_print(const priority_queue<T, C, Comp>& pq0) {
        auto pq = pq0;
        vector<T> v;
        while (!pq.empty()) v.push_back(pq.top()), pq.pop();
        debug_print(v);
    }
    template<class T>
    void debug_print(const T& x) {
        if constexpr (is_same_v<T, char>) {
            cerr << '\'' << x << '\'';
        } else if constexpr (is_same_v<T, bool>) {
            cerr << (x ? "true" : "false");
        } else if constexpr (is_same_v<T, nullptr_t>) {
            cerr << "nullptr";
        } else if constexpr (is_integral_v<T>) {
            cerr << +x;
        } else if constexpr (is_floating_point_v<T>) {
            cerr << x;
        } else {
            cerr << '{';
            bool first = true;
            for (const auto& e : x) {
                if (!first) cerr << ", ";
                first = false;
                debug_print(e);
            }
            cerr << '}';
        }
    }
    void debug_out() {}
    template<class T, class... Ts>
    void debug_out(const T& x, const Ts&... xs) {
        cerr << ' ';
        debug_print(x);
        debug_out(xs...);
    }
#endif
