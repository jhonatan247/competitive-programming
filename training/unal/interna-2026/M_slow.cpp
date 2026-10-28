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
 
struct Node {
    int value;
    vector<Node*> children;

    Node(int value): value(value){}

    void insertChild(Node * newNode){
        children.pb(newNode);
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    vector<Node*> graph(n);

    F0R(i,n){
        cin>>s;
        Node * currentNode = new Node(i + 1);
        if(graph[i]) currentNode = graph[i];

        graph[i] = currentNode;
        F0R(j,sz(s)){
            if(s[j] == '?' or s[j] == 'W'){
                if(graph[j]){
                    currentNode->insertChild(graph[j]);
                }else{
                    Node * newNode = new Node(j + 1);
                    currentNode->insertChild(newNode);
                    graph[j] = newNode;
                }
            }
        }
    }
    
    unordered_set<int> winners;
    
    trav(node, graph){
        unordered_set<int> visited;
        queue<Node*> bfs;
        bfs.push(node);
        visited.ins(node->value);

        while(sz(bfs)){
            Node* currentNode = bfs.front();
            bfs.pop();       
            
            trav(child,currentNode->children){
                if(winners.count(child->value)){
                    winners.ins(node->value);
                    goto out;
                }
                if(!visited.count(child->value)){
                    visited.ins(child->value);
                    bfs.push(child);
                }
                if(sz(visited) == n) goto out;
            }
        }

        out:
        if(sz(visited) == n) winners.ins(node->value);
    }

    vector<int> sortedWinners(all(winners));
    sort(all(sortedWinners));

    trav(winner,sortedWinners) cout << winner << endl;
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


