#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a,a+n);
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (a[i] >= ans){
                ans ++;
        }
        cout << ans - 1<< "\n";

}
