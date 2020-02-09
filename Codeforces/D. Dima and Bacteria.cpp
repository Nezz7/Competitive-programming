#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 9;
int root[MAXN], a[600], dist[600][600];
vector<int> type;
int find_set (int x){
    if (root[x] == x) return x;
    return root[x] = find_set(root[x]);
}
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (u < v) swap(u,v);
    root[v] = u;
}
int main (){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n ; i++)
        root[i + 1] = i + 1;
    for (int i  = 0; i < k; i++){
        cin >> a[i];
        for (int j = 0; j < a[i]; j++)
            type.push_back(i);
    }
    for (int i = 0; i < k ;i++)
        for (int j = 0; j < k ;j++)
            dist[i][j] = INT_MAX;
    for (int i = 0; i < m ;i ++){
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0){
            union_set(u, v);
        }
        int x = type[u - 1];
        int y = type[v - 1];
        dist[x][y] = min(dist[x][y],w);
        dist[y][x] = dist[x][y];
    }
    bool is_valid = true;
    int last = 1;
    for (int i = 0; i < k; i++){
        for (int j = last; j < a[i] + last - 1 ; j++){
            if (find_set(j) != find_set(j + 1)) is_valid = false;
        }
        last += a[i] ;
    }
    if (!is_valid){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i  = 0 ; i < k ;i ++)
        dist[i][i]=0;
    for (int x = 0; x < k ;x++){
        for (int i = 0; i < k ;i++)
            for (int j = 0; j < k ;j++)
                    if (dist[i][x] < INT_MAX && dist[x][j] < INT_MAX)
                        dist[i][j] = min(dist[i][x] + dist[x][j],dist[i][j]);
    }

    for (int i = 0; i < k ;i++){
        for (int j = 0; j < k ;j++)
            if (dist[i][j] == INT_MAX ) cout << -1 << " ";
            else cout << dist[i][j] << " ";
            cout << "\n";
    }
}

