#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

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

using namespace std;

typedef long long _ll;
typedef long double _ld;
 
#define F0R(i, a) for (int i=0; i<(a); i++)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
 
void solve(int n, int m) {
    string s;
    cin >> s;

    vector<int> arr(n);
    F0R(i, n) {
        arr[i] = s[i] - '0';
    }

    _ll maxsum = 0;
    _ll currsum = 0;
    for(int i = 0; i < n; i+=2) {
        currsum += arr[i];
        maxsum = max(maxsum, currsum);
        debug(maxsum, currsum, i, arr[i]);
        if(i >= 2 * (m- 1)) {
            currsum -= s[i - 2 * (m - 1)];
        }
    }
    
    currsum = 0;
    for(int i = 1; i < n; i+=2) {
        currsum += arr[i];
        maxsum = max(maxsum, currsum);
        debug(maxsum, currsum, i, arr[i]);
        if(i >= 2 * (m- 1)) {
            currsum -= s[i - 2 * (m - 1)];
        }
    }

    cout << maxsum << nl;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    while(n != 0 and m != 0) {
        solve(n, m);
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
        cin >> n >> m;
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}

// TODO: Print pointer arrays
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
