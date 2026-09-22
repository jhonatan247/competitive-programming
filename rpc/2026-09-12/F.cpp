#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int vcount = 0, ycount = 0;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'y') ycount++;
        else{
            for(int j = 0; j < vowels.size(); j++){
                if(s[i] == vowels[j]){
                    vcount++;
                    break;
                }
            }
        }
    }
    
    cout << vcount << ' ' << ycount + vcount << endl;

    return 0;
}
