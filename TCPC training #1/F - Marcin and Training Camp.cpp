#include <bits/stdc++.h>
#define LL long long int
using namespace std;
vector<set<int>> adj;
int const MAXN = 8000;
LL a[MAXN], b[MAXN],A[MAXN];
LL ans;
int tree[4*MAXN];
void build(int node, int start, int end){
    if (start == end){
         tree[node] = start;
         return ;
    }
    int mid = (start + end)/2;
    build (2*node, start, mid);
    build (2*node+1, mid+1, end);
    if (A[tree[2*node+1]] >  A[tree[2*node]])
        tree[node] = tree[2*node+1];
    else   tree[node] = tree[2*node];
}
void update (int node, int start, int end, int idx, int val){
    if (idx < start or idx  > end ) return;
    if (start == end){
        A[start] = val;
        return;
    }
    int mid = (start + end)/2;
    if (start <= idx && idx <= mid){
        update (2*node,start,mid,idx,val);
    }else  update (2*node+1,mid+1,end,idx,val);
    if (A[tree[2*node+1]] >  A[tree[2*node]])
        tree[node] = tree[2*node+1];
    else   tree[node] = tree[2*node];
}
int main (){
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j], ans += b[j];
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            bitset<60> l (a[i]);
            bitset<60> r (a[j]);
            for (int k = 0; k < 60; k++){
                if(l[k] && !r[k]) adj[i].insert(j);
                if(!l[k] && r[k]) adj[j].insert(i);
            }
        }
    }

    for (int i = 0; i < n; i++){
      A[i] = adj[i].size();
    }
    build(1,0,n-1);
    int team = n;
    int l = 9000;
    int u = tree[1];
    while (u != l && A[u]>= team - 1){
        if (A[u] == team - 1){
            ans -= b[u];
            update(1,0,n-1,u,-1);
            for (int i = 0; i < n; i++){
                if (u == i) continue;
                adj[i].erase(u);
                update(1,0,n-1,i,adj[i].size());
            }
            team--;
        }
        l = u;
        u = tree[1];
    }
    if (team < 2) ans = 0;
    cout << ans  << "\n";
}
