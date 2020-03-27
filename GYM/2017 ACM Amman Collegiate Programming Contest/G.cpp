#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 3000;
int n;
int a[MAXN];
LL gcd(LL a, LL b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}
LL lcm (LL a, LL b){
   if(a>1e13)
        return 1e18;
	LL g = gcd(a, b);
	if (double(a) / g*b > 1e13)
		return 1e18;
	return a / g*b;
}
int main (b){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int res = 0;
		LL sum, x;
		for (int i = 0; i < n; ++i) {
			sum = 0;
			x = 1;
			for (int j = i; j < n; ++j) {
				sum += a[j];
				x = lcm(x, a[j]);
				if (sum%x == 0)
					++res;
			}
		}
		printf("%d\n", res);
    }
}