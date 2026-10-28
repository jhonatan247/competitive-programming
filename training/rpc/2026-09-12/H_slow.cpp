#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main()
{
    ll n, k, p;
    cin >> n >> k >> p;
    vector<long long>divisores;
    for(long long i=1;i*i<=n; i++){
        if(n%i==0){
            long long r=n/i;
            divisores.push_back(i);
            if(r!=i)divisores.push_back(r);
        }
    }
    sort(divisores.begin(),divisores.end());
    vector<long long>ans;
    for(auto it:divisores){
        if(it>k)break;
        if(n/it <=p)ans.push_back(it);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it<<endl;

    return 0;
}