#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define fill0(a) memset(a, 0, sizeof a)
#define fill(a, v) memset(a, v, sizeof a)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const _ll MX = 200001;


void solve() {
    _ll a, b, k;
    cin >> a >> b >> k;
    
    vector<int> A(k);
    map<int, _ll> Acnt;
    F0R(i, k) {
        cin >> A[i];
        if(!Acnt.count(A[i])) Acnt[A[i]] = 0;
        Acnt[A[i]]++;
    }
    
    vector<int> B(k);
    map<int, _ll> Bcnt;
    F0R(i, k) {
        cin >> B[i];
        if(!Bcnt.count(B[i])) Bcnt[B[i]] = 0;
        Bcnt[B[i]]++;
    }

    
    _ll sub = 0;
    TRAV(e, Acnt) {
        sub += (e.sc * (e.sc - 1)) / 2;
    }
    TRAV(e, Bcnt) {
        sub += (e.sc * (e.sc - 1)) / 2;
    }

    _ll ans = (k * (k - 1)) / 2 -  sub;

    cout << ans << nl;
    
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


