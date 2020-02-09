#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int ret = 0;
    LL g = 0;
    for (int i = 0; i < n; i ++){
        LL x;
        cin >> x;
        g = __gcd(x,g);
    }
    for (LL i = 1; i*i <= g; i++){
         if (g % i == 0){
                LL x = g/i;
                if (x != i) ret +=2;
                else ret++;
         }
    }
    cout << ret;
}
