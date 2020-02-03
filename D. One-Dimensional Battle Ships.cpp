#include <bits/stdc++.h>
using namespace std;
int n, m, k,a;
const int MAXN = 2e5+9;
bool vis[MAXN];
int x[MAXN];
bool check (int mid ){
    memset(vis,false,sizeof vis);
    int need =   k ;
    for (int i = 0; i <= mid ; i++)
            vis[x[i]] = true;
    for (int i = 1 ; i <= n ;i++){
        if (vis[i] && i+a <= n && vis[i+a]){
            for (int j = i; j <= min(i+a,n); j++)
                vis[j] = true;
        }
        if (vis[i] && i+a> n){
            for (int j = i; j <=n ; j++)
                vis[j] = true;
            break;
        }
        if (vis[i] && i <= a){
            for (int j = i; j >= 0; j--)
                vis[j] = true;
        }
    }
    int cur =0;
    int have = 0;
    for (int i =1; i <=n; i++){
        if (!vis[i]) cur++;
        else {
            have += (cur+1) /(a+1);
            cur = 0;
        }
    }
        have += (cur+1) /(a+1);
    return  need > have;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0); cout . tie(0);
    cin >> n >> k >> a;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x[i];
    }
    int L = 0, R =  m - 1;
    int ans = -1;
    while (L <= R){
        int mid = (L+R +1)/2;
        if (check (mid)){
                ans = mid + 1;
                R = mid - 1;
        }else L = mid  + 1;
    }
    cout << ans;
}
