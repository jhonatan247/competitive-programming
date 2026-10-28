#ifdef LOCAL
    #define _GLIBCXX_DEBUG
// >>> ~/cp/library/local/debug.h
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
        cerr << +x;                       // promote char8_t/int8_t etc.
    } else if constexpr (is_floating_point_v<U>) {
        cerr << x;
    } else if constexpr (is_iterable<T>::value) {
        cerr << '{';
        bool first = true;
        for (const auto& e : x) {
            if (!first) cerr << ", ";
            first = false;
            debug_print(e);
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

// <<< ~/cp/library/local/debug.h
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>
// >>> ~/cp/library/modular.h
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}
 
template <typename T>
class Modular {
    public:
    using Type = typename decay<decltype(T::value)>::type;
 
    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }
 
    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }
 
    const Type& operator()() const {
        return value; 
    }
    template <typename U>
    explicit operator U() const {
        return static_cast<U>(value); 
    }
    constexpr static Type mod() {
        return T::value; 
    }
 
    Modular& operator+=(const Modular& other) {
        value += other.value; value -= (value >= mod()) * mod(); return *this; 
    }
    Modular& operator-=(const Modular& other) {
        value -= other.value; value += (value < 0) * mod(); return *this; 
    }
    template <typename U> Modular& operator+=(const U& other) {
        return *this += Modular(other);
    }
    template <typename U> Modular& operator-=(const U& other) {
        return *this -= Modular(other);
    }
    Modular& operator++() {
        return *this += 1;
    }
    Modular& operator--() {
        return *this -= 1;
    }
    Modular operator++(int) {
        Modular result(*this); *this += 1; return result;
    }
    Modular operator--(int) {
        Modular result(*this); *this -= 1; return result;
    }
    Modular operator-() const {
        return Modular(-value);
    }
 
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(int64_t(uint64_t(value) * uint64_t(rhs.value) - uint64_t(q) * uint64_t(mod())));
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }
 
    Modular& operator/=(const Modular& other) {
        return *this *= Modular(inverse(other.value, mod()));
    }
 
    friend const Type& abs(const Modular& x) {
        return x.value;
    }
 
    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
    template <typename V, typename U>
    friend V& operator>>(V& stream, Modular<U>& number);
 
    private:
    Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value == rhs.value;
}
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) {
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) == rhs;
}
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value < rhs.value;
}
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}
 
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
    return stream << number();
}
 
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}
 
// using ModType = int;
 
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;
 
// constexpr int md = 998244353;
// using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
// <<< ~/cp/library/modular.h

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ll MOD7 = 1000000007;
const _ll MOD9 = 1000000009;
const _ll MOD = 998244353;

using Mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

void solve() {
    _ll n, m, r, c;
    cin >> n >> m >> r >> c;
    
    Mint base = 2;

    cout << power(base, n * m - (n - r + 1) * (m - c + 1)) << nl; 
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


