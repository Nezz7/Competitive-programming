#include <bits/stdc++.h>
using namespace std;
int n,k;
int T[600],stops[600];
vector<vector<pair<int,int>>> adj;
int dist[600];
int dij (int k){
    for (int i = 0; i < 600; i++)
        dist[i]  = 1e9;
    dist[0] = 0;
    dist[100] = 0;
    dist[200] = 0;
    dist[300] = 0;
    dist[400] = 0;
    priority_queue <pair <int,int> , vector <pair <int,int> >, greater <pair <int,int> > >pq;
    pq.push (make_pair(0,0));
    pq.push (make_pair(0,100));
    pq.push (make_pair(0,200));
    pq.push (make_pair(0,300));
    pq.push (make_pair(0,400));
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
                pq.push(make_pair(dist[child],child));
            }
        }
    }
    int ret = 1e9;
    for (int i = 0; i < 5; i++)
        ret = min(ret,dist[i*100+k]);
    return ret;
}
int main (){
while(scanf("%d %d", &n, &k) == 2){
      adj.resize(600);
      for( int i = 0; i < n; i++ )
        scanf("%d", &T[i]);
        string line;
        stringstream ss;
        getline(cin, line);
        for( int i = 0; i < n ; i++ ){
            int ind = 0;//clearv
            getline(cin, line);
            ss.clear();
            ss << line;
            ind = 0;
            while(ss >> stops[ind++]);
            ind --;

            for (int j = 0; j < ind -1; j++ ){
                int dif = stops[j+1] - stops[j];
                adj[i*100+stops[j]].push_back({i*100+stops[j+1],dif*T[i]});
                adj[i*100+stops[j+1]].push_back({i*100+stops[j],dif*T[i]});
            }
        }
        for (int i = 0; i < 100; i++){
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 5; k++){
                    adj[i+j*100].push_back({i+k*100,60});
                }
        }
        int ans = dij(k);
        if (ans  != 1e9)
            cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
        adj.clear();
    }

}
