LL dij(){
    priority_queue <pair <LL,int> , vector <pair <LL,int> >, greater <pair <LL,int> > >pq;
    for(int i = 0; i <= n; i++)
        dist[i] = inf;
    pq.push ({0,1});
    dist[1] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto cur : g[u]){
            int child = cur.first;
            LL w = cur.second;
            if (dist[child] > dist[u] + w){
                dist[child] = dist[u] + w;
                pq.push( { dist[child], child } );
            }
        }
    }
    return dist[n];
}