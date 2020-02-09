#include <bits/stdc++.h>
using namespace std;
int main (){
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        int n,m,k;
        c++;
        cin >> n >> k >> m;
        double f [m+2],p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < m ; i++)
            f[i] = 0;
        f[1] = p[0];
        for (int i = 2; i <= m ; i++){
            for (int j = 0; j < n;j++){
                f[i] += p[j]*pow(f[i-1],j);
            }
        }
        printf ("Case #%d: %.7f\n",c,pow(f[m],k));
    }
}
