#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using ld  = long double;
using ull = unsigned long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);

    int n; cin >> n;
    vector<ull> a(n);
    for (ull& num : a) cin >> num;
    
    ull ans = 0;
    for (int i = 0; i < 62; i++) {
        ull ith_bit = (1ULL << i);
        for (ull num : a) {
            if (num & ith_bit) { 
                ans |= ith_bit;
                break;
            }
        }
        if (ans & ith_bit) continue;
        ull s = 0;
        for (ull num : a) {
            s += num % ith_bit;
            if (s & ith_bit) {
                ans |= ith_bit;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}