#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a ,b;
    
    cin >> n >> a >> b;
    int w;
    bool missingA = true, missingB = true, lessThanA = false, greaterThanB = false;
    
    for(int i = 0; i < n - 1; i++){
        cin>>w;
        missingA = missingA && w != a;
        missingB = missingB && w != b;
        lessThanA = lessThanA || w < a;
        greaterThanB = greaterThanB || w > b;
    }
    
    if(missingA and missingB or lessThanA or greaterThanB){
        cout << -1 << endl;
    }
    else if(missingA){
        cout << a << endl;
    }
    else if (missingB){
        cout << b << endl;
    }
    else{
        for(int i = a; i < b; i++){
            cout << i << " ";
        }
        cout << b << endl;
    }

    return 0;
}