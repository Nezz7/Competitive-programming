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
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    LL ans[n + 1];
    LL d = 1;
    LL cur = 0;
    ans [0] = 0;
    int start = 0;
    int nxt = 0;
    for (int i = 0 ; i < n ; i++){
        cur ++;
        if (cur <= m ){
            ans[i + 1] = ans[i] + a[i];
        }else {
              ans [i + 1] =  ans[i] + a[i]  + a[start] ;
               int cc = start - m;
               int x = 0;
               while (cc >= 0){
                    x +=a[cc],cc-=m;
               }
               cout << x<< " ";
              start ++;

        }
    }

    cout << endl;
    for (int i = 0; i < n ; i++)
        cout << ans[i + 1] << " ";

}
