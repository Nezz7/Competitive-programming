#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main(){
    /*ios_base::sync_with_stdio(0);
    cin . tie(0) , cout.tie(0);*/
    int n;
    cin >> n;
    while (n--){
        LL r,b,k;
        cin >> r >> b >> k;
        LL  a = min(r,b);
        b = max(r,b);
        LL g =__gcd(a,b);
        bool cond = (b-g+a-1)/a < k;
        if (cond )
            cout << "OBEY\n";
        else cout << "REBEL\n";
    }

}
