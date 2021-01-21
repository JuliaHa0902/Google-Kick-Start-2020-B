#include <bits/stdc++.h>
using namespace std;

int main () {
	int T;
	cin >> T;
	long long n, d;
	long long a[10000];
	for (int t = 1; t <= T; t++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		} 
		long long result = d;
		for (int i = n; i > 0; i--) {
			result = result - d % a[i];
			d = result;
		}
		cout << "Case #" << t << ": " << result << "\n";
	}
	return 0;
}