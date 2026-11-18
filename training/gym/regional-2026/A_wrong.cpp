#ifdef LOCAL
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

#define nl endl;

void solve() {
        int n;
    cin >> n;

    vector<int> colors;
    int pivot = -1;

    if (n <= 3)
    {
        pivot = 2;
        for (int i = 0; i < n - 1; i++)
        {
            colors.push_back(1);
        }
        colors.push_back(2);
    }
    else if(n == 4) {
        pivot = 2;
        for (int i = 0; i < n - 2; i++)
        {
            colors.push_back(1);
        }
        colors.push_back(2);
        colors.push_back(2);
    }
    else
    {
        pivot = 3;
        int curr = 1;
        for (int i = 0; i < n - 1; i += 2)
        {
            colors.push_back(curr);
            if (sz(colors) < n - 1)
                colors.push_back(curr);
            if (curr == 1)
                curr = 2;
            else
                curr = 1;
        }
        colors.push_back(3);
    }

    cout << pivot << ' ';
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << colors[i];
    }
    cout << endl;

    int q;
    cin >> q;

    while (q--)
    {
        int m;
        cin >> m;

        vector<int> path(m);
        int curr_pivot = -1;
        int init = -1;
        for (int i = 0; i < m; i++)
        {
            cin >> path[i];
            if(init == -1) init = path[i];
            if (n != 4 and curr_pivot == -1 and path[i] == pivot)
            {
                curr_pivot = i;
            }
            if(n == 4 and init != path[i] and curr_pivot == -1) {
                curr_pivot = i;
            }
        }

        debug(init);

        deque<int> ans;
        int indx = -1;
        if(n != 4) {
            ans.push_back(n);
            indx = n - 1;
        } else {
            if(init == 1) {
                indx = 2;
            } else {
                indx = 1;
            }
            ans.push_back(indx + 1);
        }
        debug(curr_pivot, indx);
        for (int i = curr_pivot + 1; i < m; i++)
        {
            if (indx == n - 1)
            {
                ans.push_back(indx);
                indx--;
            }
            else if (indx == 0)
            {
                indx++;
                ans.push_back(indx + 1);
            }
            else
            {
                int next = path[i];
                if (colors[indx + 1] == next)
                {
                    indx++;
                    ans.push_back(indx + 1);
                }
                else
                {
                    ans.push_back(indx);
                    indx--;
                }
            }
        }
        debug(ans);
        if(n != 4) {
            indx = n - 1;
        } else {
            if(init == 1) {
                indx = 2;
            } else {
                indx = 1;
            }
        }
        for (int i = curr_pivot - 1; i >= 0; i--)
        {
            if (indx == n - 1)
            {
                ans.push_front(indx);
                indx--;
            }
            else if (indx == 0)
            {
                indx++;
                ans.push_front(indx + 1);
            }
            else
            {
                int next = path[i];
                if (colors[indx + 1] == next)
                {
                    indx++;
                    ans.push_front(indx + 1);
                }
                else
                {
                    ans.push_front(indx);
                    indx--;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


