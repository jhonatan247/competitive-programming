#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, lph, loc;
    
    cin >> n >> lph;
    
    vector<int> problems;
    
    for(int i = 0; i < n; i ++){
        cin >> loc;
        problems.push_back(loc);
    }
    
    sort(problems.begin(), problems.end());
    
    int problemCount = 0, totalLines = lph * 5;
    for(int i = 0; i < n; i++){
        if(totalLines < problems[i]) break;
        totalLines -= problems[i];
        problemCount++;
    }
    
    cout << problemCount << endl;

    return 0;
}