#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n;i++)
            cin >> a[i];
        bool cond = true;
        for (int i = 0; i < n - 1; i++)
            if (abs(a[i]-a[i+1])!= 1 && abs(a[i]-a[i+1])!= n-1){
                cond = false;
                break;
            }
        if (cond) cout << "YES\n";
        else cout << "NO\n";
    }
}
