#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main()
{
    int k, p;
    cin >> k >> p;
    
    vector<int> pot(k + 3, 1);
    
    for (int i = 1; i <= k + 2; i++)
        pot[i] = (pot[i - 1] * 10LL) % p;

    ll ans = 0;

    vector<ll> impar(p, 0);

    for(int d = 0; d <= 9; d++)
        impar[d % p]++;

    ans = impar[0];

    for (int L = 1; L + 2 <= k; L += 2) {
        vector<ll> nxt(p, 0);
        int coef = (pot[L + 1] + 1) % p;
        for (int r = 0; r < p; r++) {
            if (impar[r] == 0) continue;
            for (int d = 0; d <= 9; d++) {
                ll nr = (r * 10LL + d * 1LL * coef) % p;
                nxt[nr] = (nxt[nr] + impar[r]) % MOD; 
                if (d != 0 &&  nr == 0) {
                    ans = (ans + impar[r]) % MOD;
                }
            }
        }
        impar.swap(nxt);
    }

    vector<ll> par(p, 0);

    par[0] = 1;

    for (int L = 0; L + 2 <= k; L += 2) {
        vector<ll> nxt(p, 0);
        int coef = (pot[L + 1] + 1) % p;
        for (int r = 0; r < p; r++) {
            if (par[r] == 0) continue;
            for (int d = 0; d <= 9; d++) {
                ll nr = (r * 10LL + d * 1LL * coef) % p;
                nxt[nr] = (nxt[nr] + par[r]) % MOD; 
                if (d != 0 && nr == 0) {
                    ans = (ans + par[r]) % MOD;
                }
            }
        }
        par.swap(nxt);
    }

    cout << ans << "\n";

    return 0; 
}
