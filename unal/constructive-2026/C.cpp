#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001; 

void solve() {
    vector<string> sudoku(9);
    F0R(i, sz(sudoku)) {
        cin >> sudoku[i];
    }

    sudoku[0][0] = sudoku[1][0];
    sudoku[1][3] = sudoku[2][3];
    sudoku[2][6] = sudoku[3][6];
    sudoku[3][1] = sudoku[4][1];
    sudoku[4][4] = sudoku[5][4];
    sudoku[5][7] = sudoku[6][7];
    sudoku[6][2] = sudoku[7][2];
    sudoku[7][5] = sudoku[8][5];
    sudoku[8][8] = sudoku[0][8];

    F0R(i, sz(sudoku)) {
        cout << sudoku[i] << nl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}


