#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        int compressedLenght = 1;
        int maxSubstract = 0;
        for(int i = 1; i < n - 1; i++){
            int prevChar = s[i - 1];
            int currentChar = s[i];
            int nextChar = s[i + 1];
            if(prevChar != currentChar){
                compressedLenght ++;
            }
            
            if(prevChar == nextChar && currentChar != prevChar){
                maxSubstract = 2;
            }
            else if (currentChar != prevChar and currentChar != nextChar){
                maxSubstract = max(maxSubstract, 1);
            }
        }
        if(s[n-1] != s[n-2]){
            compressedLenght ++;
        }
        cout << compressedLenght - maxSubstract << endl;
    }
    return 0;
}
