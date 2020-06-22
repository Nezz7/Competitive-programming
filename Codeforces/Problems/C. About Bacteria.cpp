#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    LL k,b,n,t;
    cin >> k >> b >> n >> t;
    LL cur = 1;
    LL ans = 0;
    for (int i  = 0; i <= n; i++){
        if (cur <= t){
            ans = n  - i ;
        }else break;
        cur = k * cur + b;
    }
    cout << ans;

}
