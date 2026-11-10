#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        set<int> numbs = {a, b, c};
        
        if(numbs.size() < 3){
            cout << 0 << endl;
            continue;
        }
        int min_numb = min({a, b, c});
        int max_numb = max({a, b, c});
        
        numbs.erase(min_numb);
        numbs.erase(max_numb);
        
        int mid_numb = *numbs.begin(); 
        
        int rounds = min(mid_numb - min_numb, max_numb - mid_numb);
        
        cout << rounds << endl;
    }
    return 0;
}

