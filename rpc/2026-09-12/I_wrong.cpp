// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        vector<int> missings;
        for(int digitos=1;digitos<=min(5,(int)s.size());digitos++){
            string w="";
            for(int j=0;j<digitos;j++){
                w+=s[j];
            }
            int empezar=stoi(w);
            int sigue=empezar+1;
            string ssigue=to_string(sigue);
            int missing = -1;
            bool success = true;
            int r = digitos;
            if(ssigue.size() != s.size())
           {     while(true){
                    if(r + (int)ssigue.size() > s.size()){
                        success = false;
                        break;
                    }
                    bool si=true;
                    for(int j=0;j<(int)ssigue.size();j++){
                        if(ssigue[j]!=s[r+j]){
                            si=false;
                            break;
                        }
                    }
                    if(si==false && missing == -1){
                        missing = sigue;
                    }
                    else if(si==false){
                        missing = -1;
                        success = false;
                        break;
                    }else{
                        r += ssigue.size();
                    }
                    if(r + (int)ssigue.size() == s.size() && si != false){
                        break;
                    }
                    sigue += 1;
                    ssigue=to_string(sigue);
                }}
            else {sigue -= 2;}
            if(success){
                if(missing != -1){
                    missings.push_back(missing);
                }else{
                    missings.push_back(empezar - 1);
                    missings.push_back(sigue + 2);
                }
            }
        }
        cout << missings.size() << endl;
        for(auto it: missings){
            cout << it << ' ';
        }
        cout << endl;
    }
}
