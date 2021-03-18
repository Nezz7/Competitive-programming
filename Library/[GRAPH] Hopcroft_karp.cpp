struct hopcroft_karp{
    vector< int > g[maxn];
    int n, m, match[maxn], dist[maxn];
    hopcroft_karp(int _n, int _m){
        n = _n;
        m = _m;
    }
    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
            if(match[i]==0) {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[0] = INF;
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
            if(u!=0) {
                len = g[u].size();
                for(i=0; i<len; i++) {
                    v = g[u][i];
                    if(dist[match[v]]==INF) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[0]!=INF);
    }
 
    bool dfs(int u) {
        int i, v, len;
        if(u!=0) {
            len = g[u].size();
            for(i=0; i<len; i++) {
                v = g[u][i];
                if(dist[match[v]]==dist[u]+1) {
                    if(dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
 
    int solve() {
        int matching = 0, i;
        memset(match, 0, sizeof match);
        while(bfs())
            for(i=1; i<=n; i++)
                if(match[i]==0 && dfs(i))
                    matching++;
        return matching;
    }
 
 
};