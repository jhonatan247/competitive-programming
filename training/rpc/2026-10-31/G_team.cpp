
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, c;
};

vector<int> bfs(int n, const vector<vector<int>>& adj) {
    vector<int> comp(n, -1);
    int id = 0;

    for (int i = 0; i < n; i++) {
        if (comp[i] != -1) continue;

        queue<int> q;
        q.push(i);
        comp[i] = id;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (comp[v] == -1) {
                    comp[v] = id;
                    q.push(v);
                }
            }
        }

        id++;
    }

    return comp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> red(n), blue(n);
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        edges[i] = {u, v, c};

        if (c == 0) {
            red[u].push_back(v);
            red[v].push_back(u);
        } else {
            blue[u].push_back(v);
            blue[v].push_back(u);
        }
    }

    // Componentes conexas de cada color
    vector<int> redComp = bfs(n, red);
    vector<int> blueComp = bfs(n, blue);

    // Verificar ciclos prohibidos
    for (const auto& e : edges) {
        if (e.c == 0) {
            if (blueComp[e.u] == blueComp[e.v]) {
                cout << "NO\n";
                return 0;
            }
        } else {
            if (redComp[e.u] == redComp[e.v]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
