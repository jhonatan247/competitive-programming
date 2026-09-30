// ============================================================
//                    SET TOOLKIT FOR CP
// ============================================================
//  All functions use descriptive names so you can USE first,
//  then read the implementation to UNDERSTAND.
// ============================================================

#include <bits/stdc++.h>
using namespace std;

// -------- PBDS (order-statistic tree) --------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

using ordered_multiset = tree<pair<int,int>, null_type, less<>,
                              rb_tree_tag, tree_order_statistics_node_update>;

// ============================================================
//  1. BASIC SET QUERIES
// ============================================================

// smallest element in set (undefined if empty)
template <class S>
auto setMin(const S& s) { return *s.begin(); }

// largest element in set (undefined if empty)
template <class S>
auto setMax(const S& s) { return *s.rbegin(); }

// true if x is in the set
template <class S, class T>
bool setContains(const S& s, const T& x) { return s.find(x) != s.end(); }

// first element >= x   (returns s.end() if none)
template <class S, class T>
auto firstAtLeast(const S& s, const T& x) { return s.lower_bound(x); }

// first element > x    (returns s.end() if none)
template <class S, class T>
auto firstGreater(const S& s, const T& x) { return s.upper_bound(x); }

// last element <= x    (returns s.end() if none)
template <class S, class T>
auto lastAtMost(const S& s, const T& x) {
    auto it = s.upper_bound(x);
    return (it == s.begin()) ? s.end() : prev(it);
}

// last element < x     (returns s.end() if none)
template <class S, class T>
auto lastLess(const S& s, const T& x) {
    auto it = s.lower_bound(x);
    return (it == s.begin()) ? s.end() : prev(it);
}

// ============================================================
//  2. INSERT / ERASE HELPERS
// ============================================================

// insert x; returns true if it was new
template <class S, class T>
bool setInsert(S& s, const T& x) { return s.insert(x).second; }

// remove x if present; returns true if removed
template <class S, class T>
bool setErase(S& s, const T& x) { return s.erase(x) > 0; }

// remove smallest element
template <class S>
void removeMin(S& s) { if (!s.empty()) s.erase(s.begin()); }

// remove largest element
template <class S>
void removeMax(S& s) { if (!s.empty()) s.erase(prev(s.end())); }

// erase ONE occurrence of x (safe for multiset)
template <class S, class T>
bool eraseOne(S& s, const T& x) {
    auto it = s.find(x);
    if (it == s.end()) return false;
    s.erase(it);
    return true;
}

// erase all elements in [l, r]
template <class S, class T>
void eraseRange(S& s, const T& l, const T& r) {
    s.erase(s.lower_bound(l), s.upper_bound(r));
}

// erase every element that satisfies pred (while iterating safely)
template <class S, class Pred>
void eraseIf(S& s, Pred pred) {
    for (auto it = s.begin(); it != s.end(); ) {
        if (pred(*it)) it = s.erase(it);
        else ++it;
    }
}

// ============================================================
//  3. RANGE / COUNT HELPERS
// ============================================================

// count elements equal to x  (O(1) for set, O(log n + k) for multiset)
template <class S, class T>
int countEqual(const S& s, const T& x) { return (int)s.count(x); }

// count elements in [l, r]
template <class S, class T>
int countInRange(const S& s, const T& l, const T& r) {
    return (int)distance(s.lower_bound(l), s.upper_bound(r));
}

// true if s is empty
template <class S>
bool setEmpty(const S& s) { return s.empty(); }

// number of elements
template <class S>
int setSize(const S& s) { return (int)s.size(); }

// ============================================================
//  4. ITERATION HELPERS
// ============================================================

// apply f to every element in sorted order
template <class S, class F>
void forEachSorted(S& s, F f) { for (auto& x : s) f(x); }

// apply f to every element in reverse sorted order
template <class S, class F>
void forEachReverse(S& s, F f) {
    for (auto it = s.rbegin(); it != s.rend(); ++it) f(*it);
}

// ============================================================
//  5. MULTISET SPECIFIC
// ============================================================

// get all elements equal to x as a vector
template <class S, class T>
vector<T> getAllEqual(const S& s, const T& x) {
    auto [lo, hi] = s.equal_range(x);
    return vector<T>(lo, hi);
}

// number of elements strictly less than x  (works on set/multiset)
template <class S, class T>
int countLess(const S& s, const T& x) {
    return (int)distance(s.begin(), s.lower_bound(x));
}

// ============================================================
//  6. ORDER-STATISTIC SET (PBDS)
// ============================================================
//  Use `ordered_set<T>` instead of `set<T>` when you need
//  index access or rank queries.

// k-th smallest element (0-indexed)
template <class T>
T kthSmallest(ordered_set<T>& os, int k) { return *os.find_by_order(k); }

// number of elements strictly less than x
template <class T>
int rankOf(ordered_set<T>& os, const T& x) { return os.order_of_key(x); }

// ============================================================
//  7. CUSTOM COMPARATOR EXAMPLES (uncomment to use)
// ============================================================

// descending order
// set<int, greater<int>> desc;

// sort pairs by second, then first
struct SortBySecond {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};
// set<pair<int,int>, SortBySecond> s;

// ============================================================
//  8. SET ALGORITHMS BETWEEN TWO SORTED SETS
// ============================================================

template <class S>
S setUnion(const S& a, const S& b) {
    S res; set_union(a.begin(), a.end(), b.begin(), b.end(),
                     inserter(res, res.begin()));
    return res;
}

template <class S>
S setIntersection(const S& a, const S& b) {
    S res; set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                            inserter(res, res.begin()));
    return res;
}

// (A - B)
template <class S>
S setDifference(const S& a, const S& b) {
    S res; set_difference(a.begin(), a.end(), b.begin(), b.end(),
                          inserter(res, res.begin()));
    return res;
}

// (A - B) ∪ (B - A)
template <class S>
S setSymmetricDifference(const S& a, const S& b) {
    S res; set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                                    inserter(res, res.begin()));
    return res;
}

// ============================================================
//  9. QUICK DEMO
// ============================================================
int main() {
    set<int> s = {10, 20, 30, 40, 50};

    cout << setMin(s) << '\n';              // 10
    cout << setMax(s) << '\n';              // 50
    cout << setContains(s, 30) << '\n';     // 1
    cout << *firstAtLeast(s, 25) << '\n';   // 30
    cout << *firstGreater(s, 30) << '\n';   // 40
    cout << *lastAtMost(s, 35) << '\n';     // 30
    cout << *lastLess(s, 30) << '\n';       // 20

    setInsert(s, 35);
    eraseOne(s, 20);
    eraseRange(s, 30, 40);
    for (int x : s) cout << x << ' ';       // 10 50
    cout << '\n';

    // multiset
    multiset<int> ms = {1, 1, 2, 2, 2, 3};
    cout << countEqual(ms, 2) << '\n';      // 3
    cout << countInRange(ms, 1, 2) << '\n'; // 5
    eraseOne(ms, 2);
    for (int x : ms) cout << x << ' ';      // 1 1 2 2 3
    cout << '\n';

    // ordered_set
    ordered_set<int> os;
    for (int x : {10, 20, 30, 40}) os.insert(x);
    cout << kthSmallest(os, 2) << '\n';     // 30
    cout << rankOf(os, 30) << '\n';         // 2

    return 0;
}
