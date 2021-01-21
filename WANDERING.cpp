#include <bits/stdc++.h>
#define oo 1000000000

using namespace std;
bool empty[400][400];
double a[400][400];

int main () {
	int T;
	int w, h, l, u, r, d;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> w >> h >> l >> u >> r >> d;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) 
				empty[i][j] = false;
		}
		for (int i = l; i <= r; i++) {
			for (int j = u; j <= d; j++) {
				empty[i][j] = true;
			}
		}
		a[1][1] = 1;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (empty[i][j]) continue;
				if ((i == 1) && (j == 1)) continue;
				a[i][j] = 0;
				if ((i > 1) && (!empty[i - 1][j])) {
					if (j == h) a[i][j] = a[i - 1][j];
					else a[i][j] = a[i - 1][j] * 0.5;
				}
				if ((j > 1) && (!empty[i][j - 1])) {
					if (i == w) a[i][j] += a[i][j - 1];
					else a[i][j] += a[i][j - 1] * 0.5;
				}
			}
		}
		printf ("Case #%d: %.9f\n", t, a[w][h]);

	}
	return 0;
}