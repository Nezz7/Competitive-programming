#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL n , m , k;
LL get_inv (LL x){
    return x/k + (x % k != 0);
}
int main (){
    cin >> n >> m >> k;
    LL a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int ans = 1;
    LL inv = get_inv(a[0]);
    LL x = 0;
    for (LL i = 0; i < m; i++){
        LL cur = get_inv(a[i] - x);
        if (inv!=cur){
            x = i ;
            inv = get_inv(a[i] - x);
            ans++;
        }
    }
    cout << ans << "\n";
}
