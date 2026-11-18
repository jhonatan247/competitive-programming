// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    for(int i = 0; i < k; i++) {
        int l = 0, r = n - 1;
        bool found = false;
        int q;
        cin >> q;
        while(l <= r) {
            int md = l + (r - l) / 2;
            if(arr[md] == q) {
                found = true;
                break;
            }
            if(arr[md] < q) {
                l = md + 1;
            } else {
                r = md - 1;
            }
        }
        if(found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
