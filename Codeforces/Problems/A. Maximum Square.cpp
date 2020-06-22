#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1000;
int occ[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0);
    cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        for (int i = 0; i < MAXN; i++) occ[i] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            occ[1]++;
            occ[x+1]--;
        }
        for (int i = 1; i <= n ; i++)
             occ[i] += occ[i-1];
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (occ[i]>=i) ans = i;
        }
        cout << ans <<"\n";
    }

}
