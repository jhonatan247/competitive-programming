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
template<class T> void debug_print(const T& x);

void debug_print(const string& s) { cerr << quoted(s); }
void debug_print(string_view s) { cerr << quoted(s); }

void debug_print(const char* s) {
    if (s) cerr << quoted(s);
    else   cerr << "nullptr";
}
void debug_print(char* s) { debug_print((const char*)s); }

template<size_t N>
void debug_print(const char (&s)[N]) { cerr << quoted(s); }

void debug_print(char c) { cerr << '\'' << c << '\''; }
void debug_print(bool b) { cerr << (b ? "true" : "false"); }
void debug_print(nullptr_t) { cerr << "nullptr"; }

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
    if constexpr (is_integral_v<T>) {
        cerr << +x;          // avoid unsigned char printing as a char
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
 
#define FOREACH(a,x) for (auto& a : x)
#define F0R(i,a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX =  100001; 

int minSort(string& s, int i, int j){
    if(i >= j) return 0;
    int f0 = -1;
    int l1 = j + 1;
    FOR(k, i, j + 1){
        if(k > f0 and s[k] == '0') f0 = k;
        if(k < l1 and s[k] == '1') l1 = k;
    }
    debug(i, j, f0, l1);
    if(f0 < l1)
        return 0;

    return 1 + min(minSort(s, l1 + 1, j), minSort(s, i, f0 - 1));
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

   for (auto it = s.rbegin(); it != s.rend(); ++it) {
    cout << *it << ' ';
} 
    if(s[0] == '1'){
        int cnt = 0;
        F0R(i, n){
            if(s[i] == '0') cnt ++;
        }
        cout << cnt << nl;
        return;
    }
    cout << minSort(s, 0, n - 1) << endl;
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

