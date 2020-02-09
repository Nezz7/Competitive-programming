 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int d[MAXN];
 vector<set<int>> g;
 vector<vector<int>> ans;
 int id;
 set<pair<int,int>> st;
 void go (int node, int i){
     if (i == 3)  return;
     st.erase({d[node],node});
     if (d[node] == 0){
        ans[id].clear();
        id--;
        return;
     }
     d[node]--;
     if(d[node] > 0){
        st.insert({d[node],node});
     }
    int x = *(g[node].begin());
    g[node].erase(x);
    g[x].erase(node);
    st.erase({d[x],x});
    ans[id].push_back(x);
    d[x]--;
    if(d[x] > 0)
    st.insert({d[x],x});
    go(x,i+1);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m ;
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; i++){
       if (d[i])
        st.insert({d[i],i});
    }
    id = 0;
    while (st.size()){
        int x = st.begin()-> second;
        if (d[x] >= 1){
            ans.push_back(vector<int>());
            ans[id].push_back(x);
            go(x,1);
            id++;
        }else st.erase({d[x],x});
    }
    cout << id << endl;
    for (int i = 0; i < id; i++){
        for (auto cur : ans[i])
            cout << cur << " ";
     cout << endl;
    }
 }

