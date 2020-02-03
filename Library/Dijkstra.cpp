#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define pb push_back
#define end "\n"
int main (){
 ios_base::sync_with_stdio(0);
 cin.tie (0);
 int T;
 cin>>T;
 while (T--){
    int n,m;
    cin>>n>>m;
    vector < vector < pair <int,int > > > adj (n+1);
    vector <long long int> dist (n+1,1e18);
   for (int i=0;i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].pb(mk(v,w));
    }
    int s,t;
    cin>>s>>t;
    dist[s]=0;
    priority_queue <pair <int,int> , vector <pair <int,int> >, greater <pair <int,int> > >pq;
    pq.push (mk(0,s));
    while (!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if (d>dist[u]) continue;
        for (int i=0;i<adj[u].size();i++){
            int child =adj[u][i].first;
            int w=adj[u][i].second;
            if (dist[child]>dist[u]+w){
                dist[child]=dist[u]+w;
                pq.push(mk(dist[child],child));
            }
        }
    }
    if (dist[t]==1e18) cout<<"NO\n";
    else cout<<dist[t]<<endl;
 }
}
