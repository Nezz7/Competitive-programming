#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int n;
vector < vector < pair <int , LL > > >  adj;
LL cost = 0;
LL get_max (int node , int p){
    LL ret = 0;
     for (auto cur : adj[node]){
        int child = cur .first;
        LL  c = cur .second;
        if (child == p) continue;
        ret = max (ret ,c + get_max(child,node));
    }
    return ret;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n ;
    adj.resize(n+1);
    for (int i = 0; i < n -1 ;i++){
        LL u,v,c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v,c);
        adj[v].emplace_back(u,c);
        cost += c;
    }

    cout<< 2*cost - get_max(1,1);
}
