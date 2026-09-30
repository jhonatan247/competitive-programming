#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#pragma GCC optimize ("O3")

#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif 

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long _ll;
typedef long double _ld;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define F0R(i, a) for (int i=0; i<(a); i++)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 
 
void solve() {
   int n, m;
   cin >> n >> m;
   
   vector<_ll> arr(n);
   F0R (i, n) {
       cin >> arr[i];
   }
   
   pq<_ll> availablePosts;
   _ll sum = 0, answer = LLONG_MIN;
   F0R(i, n) {
       if(sz(availablePosts) == m - 1){
            answer = max(answer, m * arr[i] - sum);
       }
       availablePosts.push(arr[i]);
       sum += arr[i];
       if(sz(availablePosts) == m){
            sum -= availablePosts.top();
            availablePosts.pop();
       }
   }
   cout << answer << nl;
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

