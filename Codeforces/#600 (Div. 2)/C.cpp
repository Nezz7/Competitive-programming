#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
LL sum[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie(0);
    int n, m;
    cin >> n >> m;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a,a+n);

    LL ans[n + 1];
    ans [0] = 0;;
    for (int i = 0 ; i < n ; i++){
            sum[i%m] += a[i];
            ans[i + 1] = ans[i] + sum[i%m];

    }
    for (int i = 0; i < n ; i++)
        cout << ans[i + 1] << " ";

}
