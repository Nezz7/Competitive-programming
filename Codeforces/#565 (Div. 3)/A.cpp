#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int dp[500];
int f (LL x){
    if (x == 1) return 0;
    int cur = 0;

        while (x % 2 == 0)
            cur ++,x/=2;
        while (x % 3 == 0)
            cur+=2,x/=3;
        while (x % 5 == 0)
            cur+=3,x/=5;
    if (x > 1) return -1;
    return cur;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0) ; cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        LL x;
        cin >> x;
        cout << f(x)<< "\n";
    }
}
