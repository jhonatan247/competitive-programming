#ifdef LOCAL
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef int64_t _ll;
typedef double _ld; // Changed from long double to double (3x-5x faster math, plenty of precision)
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<bool> _vb;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvd> _vvvd;

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)
#define P_TRAV(k, a, x) for (auto& [k, a] : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ld INF = 1e18;

static _ld dp[105][105][105];

struct Point {
    _ld x, y;
};

inline _ld distanceBetween(const Point& a, const Point& b) {
    _ld dx = a.x - b.x;
    _ld dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

inline _ld crossProduct(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

inline bool isLeftTurn(const Point& A, const Point& B, const Point& C) {
    return crossProduct(A, B, C) > 0;
}

vector<Point> getSortedCandidatesAbove(Point anchor, const vector<Point>& allCows) {
    vector<Point> candidates;
    candidates.reserve(sz(allCows));
    TRAV(p, allCows) {
        bool isStrictlyAbove = (p.y > anchor.y);
        bool isSameRowToRight = (p.y == anchor.y && p.x > anchor.x);
        if (isStrictlyAbove || isSameRowToRight) {
            candidates.push_back(p);
        }
    }

    sort(candidates.begin(), candidates.end(), [&](const Point& a, const Point& b) {
        _ld cp = crossProduct(anchor, a, b);
        if (cp != 0) return cp > 0;
        return distanceBetween(anchor, a) < distanceBetween(anchor, b);
    });

    return candidates;
}

_vvi countPointsInsideTriangles(const vector<Point>& candidates) {
    int m = sz(candidates);
    _vvi insideCount(m, _vi(m, 0));

    F0R(i, m) {
        FOR(j, i + 1, m) {
            int count = 0;
            FOR(k, i + 1, j) {
                if (isLeftTurn(candidates[i], candidates[j], candidates[k])) {
                    count++;
                }
            }
            insideCount[i][j] = count;
        }
    }
    return insideCount;
}

int maxCowsWithAnchor(Point anchor, const vector<Point>& allCows, _ld maxRope) {
    int best = 1;

    vector<Point> candidates = getSortedCandidatesAbove(anchor, allCows);
    int m = sz(candidates);

    _vd distAnchor(m);
    F0R(i, m) {
        distAnchor[i] = distanceBetween(anchor, candidates[i]);
        if (2.0 * distAnchor[i] <= maxRope) {
            best = max(best, 2);
        }
    }

    if (m < 2) return best;

    _vvd distPair(m, _vd(m, 0.0));
    F0R(i, m) {
        FOR(j, i + 1, m) {
            distPair[i][j] = distanceBetween(candidates[i], candidates[j]);
        }
    }

    _vvi insideCount = countPointsInsideTriangles(candidates);
    int totalCows = sz(allCows);

    for (int count = 3; count <= totalCows; count++) {
        F0R(last, m) {
            F0R(prev, last) {
                dp[count][last][prev] = INF;
            }
        }
    }

    F0R(i, m) {
        _ld distAnchorToI = distAnchor[i];
        if (distAnchorToI > maxRope) continue;

        FOR(j, i + 1, m) {
            _ld openPathLen = distAnchorToI + distPair[i][j];
            if (openPathLen >= maxRope) continue;

            int cowsEnclosed = 3 + insideCount[i][j];
            dp[cowsEnclosed][j][i] = openPathLen;

            _ld closedLoopLen = openPathLen + distAnchor[j];
            if (closedLoopLen <= maxRope) {
                best = max(best, cowsEnclosed);
            }
        }
    }

    for (int count = 3; count <= totalCows; count++) {
        FOR(last, 1, m) {
            F0R(prev, last) {
                _ld currentLen = dp[count][last][prev];
                if (currentLen >= maxRope) continue;
                
                FOR(nxt, last + 1, m) {
                    _ld newLen = currentLen + distPair[last][nxt];
                    if (newLen >= maxRope) continue;

                    if (!isLeftTurn(candidates[prev], candidates[last], candidates[nxt])) {
                        continue;
                    }

                    int newCount = count + 1 + insideCount[last][nxt];

                    if (newLen < dp[newCount][nxt][last]) {
                        dp[newCount][nxt][last] = newLen;

                        _ld closedLoopLen = newLen + distAnchor[nxt];
                        if (closedLoopLen <= maxRope) {
                            best = max(best, newCount);
                        }
                    }
                }
            }
        }
    }

    return best;
}

void solve() {
    int n;
    _ld maxRope;
    
    cin >> n >> maxRope;

    vector<Point> cows(n);
    F0R(i, n) {
        cin >> cows[i].x >> cows[i].y;
    }

    int overallMaxCows = 1;
    TRAV(anchor, cows) {
        int captured = maxCowsWithAnchor(anchor, cows, maxRope);
        overallMaxCows = max(overallMaxCows, captured);
    }

    cout << overallMaxCows << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}
