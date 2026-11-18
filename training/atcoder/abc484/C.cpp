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
typedef long double _ld;
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

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    F0R(i, n) {
        cin >> A[i];
    }
    
    vector<int> B(n);
    F0R(i, n) {
        cin >> B[i];
    }
    
    int indx = -1;
    int miss = -1;
    F0R(i, n) {
        if(A[i] != B[i] and indx == -1) {
            indx = i;
            miss = A[i];
            break;
        }
    }

    if(indx == -1) {
        cout << "Yes" << nl;
        return;
    }

    if(indx == n - 1) {
        cout << "No" << nl;
        return;
    }

    bool cas = A[indx + 1] == B[indx];

    int curr = indx + 1;

    if(cas) {
        while(curr < n and A[curr] == B[curr - 1]) curr ++;
        _vi tmp = A;
        tmp.erase(tmp.begin() + indx);
        tmp.insert(tmp.begin() + (curr - 1), miss);
        if(tmp == B) {
            cout << "Yes" << nl;
            return;
        }
    }

    curr = indx + 1;
    while(curr < n - 1 and A[curr] == B[curr + 1]) curr ++;
    int next = A[curr]; 
    _vi tmp = A;
    tmp.erase(tmp.begin() + curr);
    tmp.insert(tmp.begin() + indx, next);
    if(tmp == B) {
        cout << "Yes" << nl;
        return;
    }

    cout << "No" << nl;

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


