//Editorial Solution
#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		int A = -1, B = -1, C = -1;
		for (int cA = 1; cA <= 2 * a; ++cA) {
			for (int cB = cA; cB <= 2 * b; cB += cA) {
				for (int i = 0; i < 2; ++i) {
					int cC = cB * (c / cB) + i * cB;
					int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
					if (ans > res) {
						ans = res;
						A = cA;
						B = cB;
						C = cC;
					}
				}
			}
		}
		cout << ans << endl << A << " " << B << " " << C << endl;
	}
	
	return 0;
}
