#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int const MAXN = 1e5+9;
vector<vector<int>>adj;
int c[3][MAXN];
ll dp[MAXN][4][4];
ll ans=0;
ll ANS[MAXN];
ll dfs (int node ,int p,int cp ,int cpp){
    if (cp == cpp && cp !=3) return 1e17;
    if (adj[node].size()==1 && p!=-1) return c[3-cp-cpp][node-1];
    ll & ret = dp[node][cp][cpp];
    if (ret!=-1) return ret;
    ret=1e17;
    for (auto child : adj[node])
        if(child != p)
             for (int i=0;i<3;i++)
                    if (i!=cp && i!=cpp)
                        ret=min(ret,c[i][node-1]+dfs(child,node,i,cp));
    return ret;
}
void print (int node ,int p,int cp ,int cpp){
    if (cp == cpp && cp !=3) return;
    if (adj[node].size()==1 && p!=-1){
        ANS[node]=3-cp-cpp+1;
        return;
    }
    for (auto child : adj[node])
        if(child != p)
             for (int i=0;i<3;i++)
                    if ( i!=cp && i!=cpp && ans-c[i][node-1]==dfs(child,node,i,cp)){
                            ANS[node]=i+1;
                            ans-=c[i][node-1];
                            print(child,node,i,cp);
                            return ;
                    }
}
int main (){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    adj=vector<vector<int>> (n+1);
    for (int j=0;j<3;j++)
    for (int i=0;i<n;i++)
        cin>>c[j][i];
    int root=-1;
    for (int i=0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (adj[i].size()>2){
            cout<<-1;
            return 0;
        }
        if (root==-1 && adj[i].size()==1){
            root=i;
        }
    }
     ans=dfs(root,-1,3,3);
    cout<<ans<<endl;
    print(root,-1,3,3);
    for (int i=1;i<=n;i++) cout<<ANS[i]<<" ";

}
