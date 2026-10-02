int * sizes;
int cnt = 0;
int maxsz = 1;

int find(int a) {
    if(parents[a] == a) return a;

    return parents[a] = find(parents[a]);
}

void union_(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(sizes[a] > sizes[b]){
        parents[b] = a;
        sizes[a] += sizes[b];
        maxsz = max(maxsz, sizes[a]);
    }
    else {
        parents[a] = b;
        sizes[b] += sizes[a];
        maxsz = max(maxsz, sizes[b]);
    }
    cnt--;
}

void remove_(int a){
    int parent = find(a);
    if(a == parent) return;
    parents[a] = a;
    sizes[parent] --;

}


void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> A(k);
    vector<int> B(k);
    F0R (i, k) {
        cin >> A[i];
        cin >> B[i];
    }

    vector<int> groups(n, 0);
    vector<int> groupcnt(n, 1);
    F0R(i, n) {
        groups[i] = i;
    }

    vector<int> Asorted = A;
    vector<int> Bsorted = B;
    sort(all(Asorted));
    sort(all(Bsorted));

    F0R(i, k) {
        if(Asorted[i] != Bsorted[i]){
            if(groups[Asorted[i] != groups[Bsorted[i]]]
        }
    }

    vector<bool> ans(k, 0);

    F0R(i, q) {
        int x, p, v;
        cin >> x >> p >> v;

    }
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
        cin >> T;
    #endif
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

