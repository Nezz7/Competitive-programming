struct LCA {
    int timer;
    int l;
    vector<int> tin, tout;
    vector<vector<int>> up,maxi;
    vector<LL> dist,dep;
    LCA(int root, int n){
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        l = ceil(log2(n + 1));
        dist.assign(n+1,0);
        dep.assign(n+1,0);
        up.assign(n+1,vector<int> (l + 1));
        maxi.assign(n+1,vector<int> (l + 1));
        dfs(root,root,0);
    }
    void dfs(int v, int p, int w){
        tin[v] = ++timer;
        up[v][0] = p;
        maxi[v][0] = w;
        for (int i = 1; i <= l; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
            maxi[v][i] = max(maxi[v][i-1],maxi[up[v][i-1]][i-1]);
        }
        for(auto cur : g[v]){
            int u = cur.first;
            int w = cur.second;
            if ( u == p ) continue;
            dep[u] = dep[v] + 1;
            dist[u] = dist[v] + w;
            dfs(u,v,w);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
    int lca (int u, int v){
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for (int i = l; i >= 0; i--){
            if(!is_ancestor(up[u][i],v))
                u = up[u][i];
        }
        return up[u][0];
    }
    LL get_dist(int u, int v){
        return dist[u] + dist[v] - 2 *dist[lca(u,v)];
    }
    LL get_best(int v, int d){
        int ret = 0;
	    for (int i = l; i >= 0; --i){
            if (d &(1 << i)){
                ret = max(ret, maxi[v][i]);
                v = up[v][i];
            }
	    }
	    return ret;
    }
};