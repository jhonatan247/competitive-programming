#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
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

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvb> _vvvb;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';
const int MX = 100001; 

void solve() {
   int n;
   cin >> n;
   _vpi arr(2 * n - 1);
   pq<pair<_pi, int>> apples;
   pq<pair<_pi, int>> oranges;
   _ll totala = 0;
   _ll totalo = 0;
   F0R (i, sz(arr)) {
       _ll a, o;
       cin >> a >> o;
       totala += a;
       totalo += o;
       arr[i] = mp(a, o);
       apples.push(mp(mp(a, o), i));
       oranges.push(mp(mp(o,a), i));
   }

   vector<bool> used(sz(arr), false);

   _ll tga = (totala + 1) / 2;
   _ll tgo = (totalo + 1) / 2;
   _ll curra = 0;
   _ll curro = 0;
   F0R(i, n) {
       while(used[apples.top().sc]) apples.pop();
       while(used[oranges.top().sc]) oranges.pop();

       _ll missa = tga - curra;
       _ll misso = tgo - curro;
       auto apple = apples.top();
       auto orange = oranges.top();
       if(curra + apple.fr.fr >= tga and curro + apple.fr.sc >= tgo) {
              curra += apple.fr.fr;
              curro += apple.fr.sc;
              used[apple.sc] = true;
              apples.pop();
              continue;
       }
       if(curra + orange.fr.sc >= tga and curro + orange.fr.fr >= tgo) {
              curra += orange.fr.sc;
              curro += orange.fr.fr;
              used[orange.sc] = true;
              oranges.pop(); 
              continue;
       }
       if(missa == misso) {
           _ll suma = apple.fr.fr + apple.fr.sc;
           _ll sumo = orange.fr.fr + orange.fr.sc;
           if(suma >= sumo) {
              curra += apple.fr.fr;
              curro += apple.fr.sc;
              used[apple.sc] = true;
              apples.pop();
           } else {
              curra += orange.fr.sc;
              curro += orange.fr.fr;
              used[orange.sc] = true;
              oranges.pop();
           }
       } else if(missa > misso) {
          curra += apple.fr.fr;
          curro += apple.fr.sc;
          used[apple.sc] = true;
          apples.pop();
       } else {
          curra += orange.fr.sc;
          curro += orange.fr.fr;
          used[orange.sc] = true;
          oranges.pop();
       }
   }

   if(curra >= tga and curro >= tgo) {
       cout << "YES" << nl;
       int usedcnt = 0;
       F0R(i, sz(arr)) {
           if(used[i]) {
               if(usedcnt) cout << ' ';
               cout << i + 1;
               usedcnt++;
           }
       }
       cout << nl;
   } else {
       cout << "NO" << nl;
   }
   
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}


