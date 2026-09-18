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
#define pii pair<int,int>

 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

const int CAMEL = 46;
const int HOLE = 79;
 
pii pairDiff(pii a, pii b){
    return mp(a.fr - b.fr, a.sc - b.sc);
}

bool isContainedMorphology(vector<pii>& contained,vector<pii>& container){
//    cout<<"COMBAT"<<endl;
//    trav(i1,contained){
//        cout<<i1.fr<<","<<i1.sc<<' ';
//    }
//    cout<<endl<<"VS"<<endl;
//    trav(i1,container){
//        cout<<i1.fr<<","<<i1.sc<<' ';
//    }
//    cout<<endl;

    if(!sz(contained)) return true;
    F0R(i,sz(container)){
        if(sz(container) - i < sz(contained)) return false;
        
        pii prevContainer = container[i];
        pii currContainer = container[i];
        
        pii prevContained = contained[0];
        pii currContained = contained[0];

        bool isContained = true;

        FOR(j, 1, sz(contained)){
            currContainer = container[i + j];
            currContained = contained[j];
            if(pairDiff(prevContainer, currContainer) != pairDiff(prevContained, currContained)){
                isContained = false;
                break;
            }          
        }
        if(isContained) return true;

    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<pii>>> adj(n, vector<vector<pii>>(m));
    vector<string> gameboard(n);

    F0R(i,n){
        cin>>gameboard[i];
//        cout << gameboard[i] << endl;
        F0R(j,m){
            if(gameboard[i][j] == HOLE){
//                cout << "H|";
                continue;
            }
            if(j > 0 && gameboard[i][j - 1] == CAMEL){ 
                adj[i][j].pb(mp(i,j-1));
//                cout<<"L";
            }
            if(j < m - 1 && gameboard[i][j + 1] == CAMEL){ 
                adj[i][j].pb(mp(i,j+1));
//                cout<<"R";
            }
            if(i > 0 && gameboard[i - 1][j] == CAMEL){ 
                adj[i][j].pb(mp(i-1, j));
                adj[i-1][j].pb(mp(i, j));
//                cout<<"UD";
            }
//            cout<<"|";
        }
//        cout << endl;
    }
//    cout << "------------" << endl;

    vector<vector<bool>> grouped(n, vector<bool>(m, false));
    vector<vector<pii>> groups;

//    trav(row, adj){
//        trav(cell, row){
//            cout<<sz(cell)<<' ';
//        }
//        cout<< endl;
//    }
//    cout<<"-----------------"<<endl;

    F0R(i,n){
        F0R(j,m){
            if(grouped[i][j] or gameboard[i][j] == HOLE) continue;
            queue<pii> bfs;
            vector<pii> group;
            group.pb(mp(i,j));
            grouped[i][j] = true;
            bfs.push(mp(i, j));

            while(sz(bfs)){
                pii cell = bfs.front();
                bfs.pop();
                trav(child,adj[cell.fr][cell.sc]){
                    if(!grouped[child.fr][child.sc]){
                        bfs.push(child);
                        group.pb(child);
                        grouped[child.fr][child.sc] = true;
                    }
                }
            }
            sort(all(group));
            groups.pb(group);
        }
    }

    vector<vector<int>> memory(sz(groups), vector<int>(sz(groups), -1));

//    trav(group, groups){
//       trav(cell, group){
//            cout<<cell.fr<<","<<cell.sc << endl;
//        }
//        cout<<"--------------"<<endl;
//    }

    int winnerCount = 0;

    F0R(i, sz(groups)){
        bool contained = false;
        F0R(j, sz(groups)){
            if(i == j) continue;
            if(memory[i][j] != -1){
                contained = memory[i][j];
                if(contained) break;
                continue;
            }
            contained=isContainedMorphology(groups[i], groups[j]);
//            cout<<"Result:"<<contained<<endl;
            memory[i][j] = contained;

            if(contained){
                memory[j][i] = sz(groups[j]) == sz(groups[i]);
                break;
            }
        }
        if(!contained) winnerCount += sz(groups[i]);
    }

    cout << winnerCount << endl;

//    cout << "==================="<<endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}


