#pragma GCC optimize ("O3")
 
#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif 
 
#include <iterator> 
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
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const char nl = '\n';
const int MX = 100001; 
 
vector<pair<int, int>> powsOf27;
 
pair<int, int> addToHash(char letter, int position, pair<int, int> currentHash){
    int letterNumber = letter - 'a' + 1;
    if(sz(powsOf27) == position){
        int firstPow = (powsOf27[position - 1].fs * 27) % MOD1;
        int secondPow = (powsOf27[position - 1].sc * 27) % MOD2;
        powsOf27.pb(mp(firstPow,secondPow));
    }
    int firstHash = (currentHash.fs + (letterNumber * powsOf27[position].fs) % MOD1) % MOD1;
    int secondHash = (currentHash.sc + (letterNumber * powsOf27[position].sc) % MOD2) % MOD2;
    return mp(firstHash, secondHash);
}
 
void solve() {
    powsOf27.push_back(mp(1,1)); 
    
    set<pair<int, int>> hashes;
 
    int n;
    string s;
    
    cin >> n;
 
    while(n--){
        cin >> s;
        pair<int,int> currentHash = {0, 0};
        for(int i = s.size() - 1; i >= 0; i--){
            int position = s.size() - 1 - i;
            currentHash = addToHash(s[i], position, currentHash);
            hashes.insert(currentHash);
        }
    }
    cout << hashes.size() << endl;
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
 
