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
typedef complex<_ld> _cd;
typedef __int128_t _i128;

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
 
void solve() {
    int n, m, k, s, d;
    cin >> n >> m >> k >> s >> d;
    
    debug(n , m, k, s, d);

    vector<map<int, _ll>> adj(n + 1, map<int, _ll>());

    F0R(i, m) {
        int v1 , v2, p;
        cin >> v1 >> v2 >> p;
        debug(v1, v2, p);   
        adj[v1][v2] = p;
        adj[v2][v1] = p;
    }

    F0R(i, k) {
        _vl dist(n + 1, LLONG_MAX);
        _vi parents(n + 1, 0);

        dist[s] = 0;
        pqg<pair<_ll, int>> nodes;
        nodes.push(mp(0, s));

        while(!nodes.empty()){
            pair<_ll, int> curr = nodes.top();
            
            nodes.pop();

            debug(curr);
            
            _ll currdist = curr.fr;

            for(const auto& [v, vd]: adj[curr.sc]) {
                _ll nextdist = currdist + vd;
                if(nextdist < dist[v]){
                    parents[v] = curr.sc;
                    dist[v] = nextdist;
                    if(v != d) {
                        nodes.push(mp(nextdist, v));
                    }
                }
            }
        }

        int currNode = d;

        while(i < k - 1 && currNode != s){
            debug(currNode);
            int parent = parents[currNode];
            adj[parent].erase(currNode);
            adj[currNode].erase(parent);
            currNode = parent;
        }

        if(i == k - 1) {
            _vi kpath;

            while(currNode != 0) {
                kpath.pb(currNode);
                currNode = parents[currNode];
            }

            cout << dist[d] << endl;

            F0Rd(j, sz(kpath)) {
                if(sz(kpath) - j - 1){
                    cout << " - ";
                }
                cout << kpath[j];
            }
            cout << nl;

        }

    }
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
