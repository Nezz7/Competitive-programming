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
 int tree[4*MAXN];
 int in[MAXN];
 vector<set<pair<int,LL>>>  adj;
 vector<pair<pair<int,int>,LL>> edges;
 void update (int node, int start, int end, int idx, int val){
    if (start == end){
         tree[node] = idx;
         in[idx] = val;
         return ;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid){
        update(2*node,start,mid,idx,val);
    }else update (2*node+1,mid+1,end,idx,val);
    int a = tree[2*node];
    int b = tree[2*node+1];
    if (in[a] < in [b]) tree[node] = tree[2*node];
    else tree[node] = tree[2*node+1];
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i  = 0; i < m ;i++){
        int a, b;
        LL w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].insert({i,w});
        adj[b].insert({i,w});
        in[a]++;
        in[b]++;
        edges.push_back({{a,b},w});
    }
    for (int i = 0; i < n ;i++){
        if (in[i] == 0) in[i] = MAXN;
        update(1,0,n-1,i,in[i]);
    }

    LL ans = 0;
    for (int i = 0; i < n ; i++){
        int mn = tree[1];
        LL mx = 0;
        if (adj[mn].size() == 0 or in[mn] == MAXN) continue;
        int p = -1;
        for (auto child : adj[mn]){
           if (child.second > mx){
                mx = child.second;
                p = child.first;
           }
        }
        ans += mx;
        int x = edges[p].first . first;
        int y = edges[p].first . second;
        adj[x].erase({p,mx});
        adj[y].erase({p,mx});
        if (in[x] != MAXN)
        update(1,0,n-1,x,in[x] - 1);
        if (in[y] != MAXN)
        update(1,0,n-1,y,in[y] - 1);
        update(1,0,n-1,mn,MAXN);
    }
    cout << ans << endl;
 }
