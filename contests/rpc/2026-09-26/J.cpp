#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
 
using namespace std;
 
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
 
int * parent;
int * sizes;
int cnt = 0;
int maxsz = 1;

int find(int a) {
    if(parent[a] == a) return a;

    return parent[a] = find(parent[a]);
}

void union_(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(sizes[a] > sizes[b]){
        parent[b] = a;
        sizes[a] += sizes[b];
        maxsz = max(maxsz, sizes[a]);
    }
    else {
        parent[a] = b;
        sizes[b] += sizes[a];
        maxsz = max(maxsz, sizes[b]);
    }
    cnt--;
}

void solve(int n, int p) {
    parent = new int[n + 1];
    sizes = new int[n + 1];
    cnt = n;
    maxsz = 1;
    FOR(i, 1, n + 1) {
        parent[i] = i;
        sizes[i] = 1;
    }

    F0R(i, p) {
        int u , v;
        cin >> u >> v;
        
        union_(u, v);
    }

    cout << cnt << ' ' << maxsz << nl;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int n, p;
    cin >> n >> p;
    while(n != 0 and p != 0) {
        solve(n, p);
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
        cin >> n >> p;
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}

