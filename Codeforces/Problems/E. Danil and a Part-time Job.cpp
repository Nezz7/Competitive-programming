#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5+9;
int L[MAXN], R[MAXN], a[MAXN], light[MAXN];
int lazy[4*MAXN],tree[4*MAXN];
int timer = -1;
vector<vector<int>> adj;
void propagate (int node, int start,int end){
    lazy[node] %= 2;
    if (lazy[node]){
        tree[node] = (end - start + 1)- tree[node];
        if (start != end){
            lazy[2*node] ++;
            lazy[2*node+1] ++;
        }
        lazy[node] = 0;
    }
}
void DFS (int node){
    a[++timer] = light[node];
    L[node] = timer;
    for (auto child : adj[node]){
        DFS(child);
    }
    R[node] = timer;
}
void build (int node, int start ,int end){
    if (end == start){
        tree[node] = a[end];
        return;
    }
    int mid = (start + end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void update (int node,int start,int end,int l,int r){
    propagate(node,start,end);
    if(r < start or end < l) return;
    if (l <= start && end <= r){
        lazy[node] ++;
        propagate(node,start,end);
        return;
    }
    int mid = (start + end)/2;
    update (2*node,start,mid,l,r);
    update (2*node+1,mid+1,end,l,r);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int query (int node,int start,int end, int l, int r){
    if(r < start or end < l) return 0;
    propagate(node,start,end);
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end)/2;
    int q1 = query(2*node,start,mid,l,r);
    int q2 = query(2*node+1,mid+1,end,l,r);
    return q1+q2;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i = 2; i<= n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n;i++)
        cin >> light[i];
    DFS(1);
    int q;
    build(1,0,n-1);
    cin >> q;
    while (q--){
        int u;
        string s;
        cin >> s >> u;
        if (s == "get"){
            cout << query(1,0,n-1,L[u],R[u]) << "\n";
        }else {
            update (1,0,n-1,L[u],R[u]);
        }
    }
}
