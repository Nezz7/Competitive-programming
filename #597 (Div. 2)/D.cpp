#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3000;
LL x[MAXN],y[MAXN],c[MAXN],k[MAXN];
int vis [MAXN];
vector<int> parent, sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        if (sz[a] == sz[b])
            sz[a]++;
    }
}
LL get (int i ,int j){
    return ((abs(x[i] - x[j]) + abs (y[i] - y[j])) * (k[i] + k[j]));
}
vector <int> build;
vector<pair<LL,pair<int,int>>> connections;
vector<pair<int,int>> edges;

int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    parent.resize(n+1);
    sz.resize(n+1);
    for (int i = 0; i <= n; i++)
        make_set(i);
    for (int i = 1 ; i <= n ; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 1 ; i <= n ; i++)
        cin >> c[i];
    for (int i = 1 ; i <= n ; i++)
        cin >> k[i];
    for (int i = 1 ; i <= n ; i++){
        connections.push_back({c[i],{0,i}});
    }
    LL cost = 0;
    for (int i = 1 ; i <= n ;i++){
        for (int j = i+1 ; j <= n ;j++){
            LL cur = get(i,j);
            connections.push_back({cur,{i,j}});
        }
    }
    sort (connections.begin(),connections.end());
    for (auto cur : connections){
        int u = cur . second . first;
        int v = cur . second . second;
        LL  w = cur . first;
        if (find_set(u) != find_set(v)){
            cost += w;
            union_sets(u,v);
            if (u == 0){
                build . push_back (v);
            }else edges.emplace_back (u,v);
        }
    }

    cout << cost << "\n";
    cout << build.size() << "\n";
    for (auto cur : build ){
         cout << cur  << " ";
    }
    cout << "\n" << edges.size()<<"\n";
    for (auto cur : edges){
        cout << cur . first  << " " << cur.second << "\n";
    }
}
