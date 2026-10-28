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
    int n;
    cin >> n;
    
    _vpi arr(n);
    F0R(i, n) {
        int val;
        cin>> val;
        arr[i] = mp(val, i);
    }

    sort(all(arr));
    debug(arr);

    if(arr[0].fr != 0){
        cout << "NO" << endl;
        debug(arr);
        return;
    }
    
    int lastA = -1, lastB = -1, lastC = -1;
    int mexA = -1, mexB = -1, mexC = -1;
    int turn = 0, lastI = 0;
    const char EMPTY = '*';
    string out(n, EMPTY);
    F0R(i, n) {
        lastI = i;
        int val, indx;
        val = arr[i].fr;
        indx = arr[i].sc;
        debug(val, indx, i, turn);
        debug(lastA, lastB, lastC);
        debug(mexA, mexB, mexC);

        if(turn % 3 == 0 or mexB != -1){
            if(lastA == -1 or lastA + 1 == val){
                lastA = val;
                out[indx] = 'A';
            }else if(lastA == val){
                if(mexB == -1) {
                    i--;
                }
                else{
                    out[indx] = 'A';
                }
            }else{
                mexA = lastA + 1;
                break;
            }
        }
        else if(turn % 3 == 1 or mexC != -1){
            if(lastB == -1){
                if(val == 0){
                    lastB = val;
                    out[indx] = 'B';
                }else {
                    mexB = 0;
                    i--;
                }
            }
            else if(lastB + 1 == val){
                lastB = val;
                out[indx] = 'B';
            }
            else if(lastB == val){
                if(mexC == -1) {
                    i--;        
                }else {
                    out[indx] = 'B';
                }
            }
            else{
                mexB = lastB + 1;
                i--;
            }
        }else {
            if(lastC == -1){
                if(val == 0){
                    lastC = val;
                    out[indx] = 'C';
                }else {
                    mexC = 0;
                    i--;
                }
            }
            else if(lastC == val or lastC + 1 == val){
                lastC = val;
                out[indx] = 'C';
            }else{
                mexC = lastC + 1;
                i--;
            }
        }
        turn ++;
    }


    if(mexA + mexC + mexB >= 2 * max({mexA, mexC, mexB})){
        FOR(i, lastI, n) {
            int indx = arr[i].sc;
            out[indx] = 'A';
        }
        cout << out << endl;
    }
    else {
        debug(out);
        cout << "NO" << nl;
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

#ifdef LOCAL
void debug_print(const string& s) { cerr << quoted(s); }
void debug_print(string_view s) { cerr << quoted(s); }
void debug_print(const char* s) {
    if (s) cerr << quoted(s);
    else   cerr << "nullptr";
}
void debug_print(char* s) { debug_print((const char*)s); }
template<size_t N>
void debug_print(const char (&s)[N]) { cerr << quoted(s); }
void debug_print(const int n) { cerr << n; }
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
