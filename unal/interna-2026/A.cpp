#pragma GCC optimize ("O3")

#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif 

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

typedef vector<vi> vvi;
typedef vector<vpi> vvpi;

typedef vector<vvi> vvvi;
typedef vector<vvpi> vvvpi;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 
 
void solve() {
    int t;
    int maxTree = 0;
    vi queries;
    unordered_set<int> trees;
    unordered_map<int, vvpi> sols;
    cin >> t;
    F0R(i, t){
        int tree;
        cin >> tree;
        queries.pb(tree);
        trees.ins(tree);
        maxTree = max(maxTree, tree);
    }

    vvpi sol;
    sol.pb(vpi());
    sol[0].pb(mp(1, 2));

    if(trees.count(2)){
        sols[2] = sol;
    }

    for(int i = 3; i <= maxTree; i += 2){
        vpi newTree;
        
        trav(tree, sol){
            for(int j = 1; j <= i / 2; j++){
                tree.pb(mp(i, j));
                newTree.pb(mp(i, i - j));
                newTree.pb(mp(i, j));
            }
        }
        if(trees.count(i)){
            sols[i] = sol;
            sols[i].pb(newTree);
        }

        vpi nextTree;

        trav(tree, sol){
            for(int j = 1; j <= i / 2; j++){
                tree.pb(mp(i + 1, i - j));
                nextTree.pb(mp(i + 1, j));
                nextTree.pb(mp(i,i - j));
            }
        }

        nextTree.pb(mp(i, i + 1));

        if(trees.count(i + 1)){
            sols[i + 1] = sol;
            sols[i + 1].pb(nextTree);
        }
        sol = sols[i + 1]; 
    }

    trav(query,queries){
        sol = sols[query];
        cout << sz(sol) << endl;
        trav(tree, sol){
            trav(node, tree){
                cout << node.fr << " " << node.sc << endl;
            }
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}


