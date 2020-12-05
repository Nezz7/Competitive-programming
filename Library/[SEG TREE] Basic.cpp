int tree[4*MAXN];
struct SegTree{
    #define T int // Type
    const T MYZERO = ; //ZERO OF F
    int n;
    SegTree(int sz){
        n = sz;
        build(1, 0, n - 1);
    }
    T merge(T a, T b){ // DEFINE
        return 
    }
    void build (int node, int start, int end){
        if (start == end){
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }
    T query (int l, int r){
        return query (1, 0, n -1, l, r) ;
     }
    T query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r);
        T p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
    void update (int node, int start, int end, int idx, T val){
        if (start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node, start, mid, idx, val);
        else 
            update(2*node + 1, mid + 1, end,idx,val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);    
    }
    void update (int idx, T val){
        update(1, 0, n - 1, idx, val);
    }
};
