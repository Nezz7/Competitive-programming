 vector<int> tree[4*MAXN];
 void build (int node, int start, int end){
    if (start == end){
        tree[node].push_back(a[start]);
        return ;
    }
    int mid = (start + end) / 2;
    build (2*node,start,mid);
    build (2*node + 1,mid+1,end);
    merge(all(tree[2*node]), all(tree[2*node+1]),back_inserter(tree[node]));
 }
 int query(int node, int start, int end, int l, int r, int k){
    if (end < l or  r < start) return 0;
    if (l <= start && end <= r) return tree[node].end() - lower_bound(all(tree[node]),k);
    int mid = (start + end) / 2;
    int p1  = query(2*node,start,mid,l,r,k);
    int p2  = query(2*node+1,mid+1,end,l,r,k);
    return p1 + p2;
 }