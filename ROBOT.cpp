#include <bits/stdc++.h>
#define oo 1000000000

using namespace std;

struct Coo {
	long long x;
	long long y;
	int time;
};

string s;
int n;
Coo a[100000];

int main () {
	int T;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		long long x = 0;
		long long y = 0;
		n = s.length();
		int top = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == ')') {
				x = (a[top].x + a[top].time * (x + oo - a[top].x)) % oo;
				y = (a[top].y + a[top].time * (y + oo - a[top].y)) % oo;
				top--;
			} else if ((s[i] - '0' >= 0) && ('9' - s[i] >= 0)) {
				top++;
				a[top].x = x; a[top].y = y; a[top].time = s[i] - '0';
			} else if (s[i] == '(') {
				continue;
			} else { 
				switch (s[i]) {
					case 'N':
						y = (y + oo - 1)% oo;
						break;
					case 'S':
						y = (y + oo + 1)% oo;
						break;
					case 'E':
						x = (x + oo + 1)% oo;
						break;
					case 'W':
						x = (x + oo - 1)% oo;
						break;
				}
			}
		}
		cout << "Case #" << t << ": " << x + 1 << " " << y + 1 << "\n";
	}
	return 0;
}