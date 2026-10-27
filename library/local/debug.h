#include <bits/stdc++.h>
using namespace std;

const char* EXECUTION_TIME = "EXECUTION_TIME";
const char* TEST_CASE_DIV_LINE = "TEST_CASE_DIV_LINE";

// ---------- forward declaration ----------
template<class T> void debug_print(const T& x);

// ---------- string-like ----------
void debug_print(const string& s) { cerr << quoted(s); }
void debug_print(string_view s) { cerr << quoted(s); }
void debug_print(const char* s) {
    if(s == EXECUTION_TIME) {
        cerr << '\n' << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec";
    } else if (s == TEST_CASE_DIV_LINE) {
        cerr << "__________________________" << '\n';
    }
    else if (s) {
        cerr << quoted(s); 
    }
    else {
        cerr << "nullptr"; 
    }
}
void debug_print(char* s) { debug_print((const char*)s); }
template<size_t N>
void debug_print(const char (&s)[N]) { cerr << quoted(s); }

// ---------- pair / tuple ----------
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

// ---------- container adaptors ----------
template<class T, class C>
void debug_print(const queue<T, C>& q0) {
    auto q = q0; vector<T> v;
    while (!q.empty()) v.push_back(q.front()), q.pop();
    debug_print(v);
}
template<class T, class C>
void debug_print(const stack<T, C>& s0) {
    auto s = s0; vector<T> v;
    while (!s.empty()) v.push_back(s.top()), s.pop();
    debug_print(v);
}
template<class T, class C, class Comp>
void debug_print(const priority_queue<T, C, Comp>& pq0) {
    auto pq = pq0; vector<T> v;
    while (!pq.empty()) v.push_back(pq.top()), pq.pop();
    debug_print(v);
}

// ---------- vector<bool> ----------
inline void debug_print(const vector<bool>& v) {
    cerr << '{';
    bool first = true;
    for (bool x : v) {
        if (!first) cerr << ", ";
        first = false;
        debug_print(x);
    }
    cerr << '}';
}

// ---------- pointers (THE FIX) ----------
template<class T>
void debug_print(T* p) {
    if (p) cerr << "ptr(" << static_cast<const void*>(p) << ")";
    else   cerr << "nullptr";
}

// Print the contents of a pointer-to-array of known length
template<class T>
void debug_print(const T* p, size_t n) {
    cerr << "@@@ [ptr, n=" << n << "] = ";
    cerr << '{';
    for (size_t i = 0; i < n; ++i) {
        if (i) cerr << ", ";
        debug_print(p[i]);
    }
    cerr << '}' << '\n';
}

// ---------- smart pointers ----------
template<class T>
void debug_print(const unique_ptr<T>& p) {
    if (p) { cerr << "uniq("; debug_print(*p); cerr << ')'; }
    else   cerr << "nullptr";
}
template<class T>
void debug_print(const shared_ptr<T>& p) {
    if (p) { cerr << "shared("; debug_print(*p); cerr << ')'; }
    else   cerr << "nullptr";
}

// ---------- optional ----------
template<class T>
void debug_print(const optional<T>& o) {
    if (o) { cerr << "some("; debug_print(*o); cerr << ')'; }
    else   cerr << "none";
}

// ---------- is_iterable trait (C++17) ----------
template<class T, class = void> struct is_iterable : false_type {};
template<class T>
struct is_iterable<T, void_t<
    decltype(begin(declval<T&>())),
    decltype(end  (declval<T&>()))
>> : true_type {};


// ---------- indentation for matrixes ----------
constexpr string INDENT_PREFIX = "  ";
int INDENT_DEPTH = 0;
string get_debug_indent() {
    string indent = "";
    for(int i = 0; i < INDENT_DEPTH; i++) {
        indent += INDENT_PREFIX;
    }
    return indent;
}

// ---------- main template ----------
template<class T>
void debug_print(const T& x) {
    using U = decay_t<T>;
    if constexpr (is_same_v<U, char>) {
        cerr << '\'' << x << '\'';
    } else if constexpr (is_same_v<U, bool>) {
        cerr << (x ? "1" : "0");
    } else if constexpr (is_same_v<U, nullptr_t>) {
        cerr << "nullptr";
    } else if constexpr (is_integral_v<U>) {
        cerr << +x; // promote char8_t/int8_t etc.
    } else if constexpr (is_floating_point_v<U>) {
        cerr << x;
    } else if constexpr (is_iterable<T>::value) {
        cerr << '{';
        bool first = true;
        bool is_matrix = false;

        INDENT_DEPTH++;
        for (const auto& e : x) {
            if (!first) {
                cerr << ", ";
            }
            if constexpr (is_iterable<decltype(e)>::value) {
                is_matrix = true;
                cerr << "\n" << get_debug_indent();
            }
            first = false;
            debug_print(e);
        }
        INDENT_DEPTH--;

        if(is_matrix) {
            cerr << '\n' << get_debug_indent();
        }
        cerr << '}';
    } else {
        cerr << "<unprintable>";
    }
}

// ---------- variadic driver ----------
void debug_out() {}
template<class T, class... Ts>
void debug_out(const T& x, const Ts&... xs) {
    cerr << ' ';
    debug_print(x);
    debug_out(xs...);
}

// ---------- macro ----------
#define debug(...) do { \
    cerr << "@@@ " << #__VA_ARGS__ << " ="; \
    debug_out(__VA_ARGS__); \
    cerr << '\n'; \
} while (0)

