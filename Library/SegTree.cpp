#include <bits/stdc++.h>
using namespace std;
int const MAXN  = 1e5 + 9;
int tree[4*MAXN];
int a[MAXN];
void build (int node, int start, int end){
    if (start == end){
        tree[node] = a[start];
        printf("tree[%d] = %d \n",node,tree[node]);
        return;
    }
    int mid = (start + end) / 2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node] + tree[2*node + 1];
    printf("tree[%d] = %d \n",node,tree[node]);
}
int query (int node, int start, int end, int l, int r){
    if (r < start or end < l) return 0;
    if (l <= start  && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node,start,mid,l,r);
    int p2 = query(2*node+1,mid+1,end,l,r);
    return p1 + p2;
}
void update (int node, int start, int end, int idx, int val){
    if (start == end){
        tree[node] = val;
        printf("tree[%d] = %d \n",node,tree[node]);
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid){
        update(2*node,start,mid,idx,val);
    }else {
         update(2*node  + 1,mid + 1, end,idx,val);
    }
    tree[node] = tree[2*node] + tree[2*node + 1];
    printf("tree[%d] = %d \n",node,tree[node]);
}
int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1,0,n-1);
    cout << query (1,0,n-1,1,3);
    update (1,0,n-1,n-1,5);
    cout << query (1,0,n-1,1,3);
}