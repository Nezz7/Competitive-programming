#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5+9;
LL sum[MAXN];
LL p[100];
map <LL,int> occ;
int main (){
    LL n, k ;
    cin >> n >> k;
    LL a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    p[0] = 1;
    int m = 1;
    LL ans = 0;
    while (p[m-1] < 1e15){
        p[m] = p[m-1] * k,m++;
        if (k == 1){
            m = 1;
            break;
        }
        if (k == -1){
            m == 2;
            break;
        }
    }
    occ[sum[n]]++;
    for (int i = n; i > 0; i--){
        for (int j = 0; j < m; j++){
            LL x = 0;
            if (i-1 >= 0) x = sum[i-1];
            ans+= occ[x + p[j]];
        }
        LL x = 0;
        if (i-1 >= 0) x = sum[i-1];
        occ[x]++;
    }
    cout << ans <<"\n";

}
