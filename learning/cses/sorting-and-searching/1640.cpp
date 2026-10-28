#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n, x;
	cin >> n >> x;
	unordered_map<int, int> values;
	for(int i = 0; i < n; i++){
		int ai;
		cin >> ai;
		if(ai >= x) continue;
		if(values.count(x - ai)){
			cout << i + 1 << " " << values[x - ai] << endl;
			return 0; 
		}
		values[ai] = i + 1;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
