#ifdef LOCAL
    #define _GLIBCXX_DEBUG
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
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    int n;
    cin >> n;
    
    string s_;
    cin >> s_;
    
    vector<bool> s(n);
    vector<int> psum(n, 0);
    vector<int> ssum(n, 0);
    int zcnt = 0;
    int ocnt = 0;
    F0R(i, n) {
        s[i] = s_[i] == '1';
        if(i) {
            psum[i] = psum[i - 1] + s[i];
        } else {
            psum[i] = s[i];
        }
        zcnt += !s[i];
        ocnt += s[i];
    }

    if(s[0]){
        cout << zcnt << nl;
        return;
    }

    F0Rd(i, n) {
        if(n - i - 1) {
            ssum[i] = ssum[i + 1] + s[i];
        } else {
            ssum[i] = s[i];
        }
    }

    debug(s);
    debug(psum);
    debug(ssum);

    int findx = -1;

    F0Rd(i, n) {
        if(ssum[i] > psum[i] and s[i]) {
            findx = i;
            break;
        }
    }

    if(findx == -1){
        cout << ocnt << nl;
        return;
    }

    int cnt = 0;

    FOR(i, findx, n) {
        cnt += !s[i];
    }

    while(s[findx]) findx --;


    F0Rd(i, findx) {
        cnt += s[i];
    }

    cout << cnt << nl;


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
