#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, c;
    
    cin >> n >> k >> c;
    
    vector<pair<int, pair<int,int>>> losers;
    vector<pair<int, pair<int,int>>> winners;
    
    map<int, int> schoolCount;
    
    int t, s;
    for(int i = 0; i < n; i++){
        cin >> t >> s;
        if(schoolCount.count(s)){
            if(schoolCount[s] >= c){
                losers.push_back(make_pair(n - i, make_pair(t, s)));
            }
            else{
                schoolCount[s] ++;
                winners.push_back(make_pair(n - i, make_pair(t, s)));
            }
        }else{
            schoolCount[s] = 1;
            winners.push_back(make_pair(n - i, make_pair(t, s)));
        }
        if(winners.size() >= k) {
            break;
        }
    }
    
    if(winners.size() < k){
        for(int i = 0; i < losers.size(); i++){
            winners.push_back(losers[i]);
            if(winners.size() >= k) break;
        }
    }
    
    sort(winners.begin(), winners.end());
    
    for(int i = winners.size() - 1; i >= 0; i--){
        int winnerId = winners[i].second.first;
        cout << winnerId << endl;
    }

    return 0;
}