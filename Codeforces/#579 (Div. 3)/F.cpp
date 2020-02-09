#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int a[17][17];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int n;
bool visited[17][17];
bool valid (int i,int j){
  return i>=0 && j>=0 && i<n && j<n;
}
ll solve (int ii,int jj,ll ans){
    cout << ii << " " << jj << " " << ans << endl;
    visited[ii][jj]=true;
    ll x = ans;
    ll ret = x;
    int cur = a[ii][jj];
    vector<pair<int,int>> v;
    bool cond = true;
    for (int k=0;k<8;k++){
        int xx=ii+dx[k];
        int yy=jj+dy[k];
        if (valid (xx,yy)){
                if (visited[xx][yy]){ cond = false;
                }else {
                    visited[xx][yy] = true;
                    v.emplace_back(xx,yy);
                }
        }
    }
    if (cond){
            ret += cur;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            if (!visited[i][j]) ret=max(solve(i,j,x+cur),ret);
            }
    }
         for (auto cur : v ){
            int xx = cur.first;
            int yy = cur.second;
            visited[xx][yy] = false;
         }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                if (!visited[i][j]) ret=max(solve(i,j,x),ret);
                }
        return ret;
}
int main (){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int T;
 cin>>T;
 while (T--){
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        cin>>a[i][j];
    ll ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
             memset(visited,false,sizeof visited);
             ll x=solve(i,j,0) ;
             ans=max(ans, x);
        }
        cout<<"ANS "<<ans<<"\n";
 }
}
