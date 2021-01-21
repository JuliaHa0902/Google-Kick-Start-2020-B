#include <bits/stdc++.h>

using namespace std;

int main () {
	int T, n;
	int a[100000];
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		int result = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 2; i < n; i++) {
			if ((a[i] > a[i - 1]) && (a[i] > a[i + 1])) result++;
		}
		cout << "Case #" << t << ": " << result << "\n";
	}
	return 0;
}