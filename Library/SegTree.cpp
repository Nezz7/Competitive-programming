struct SegTree{
    #define T int // Type
    vector<T> tree;
    vector<T> a;
    const int MYZERO = ; //ZERO OF F
    SegTree(vector<int>&v){
        int n = v.size();
        a.assign(n, 0);
        tree.assign(4*n, 0);
        for(int i = 0; i < n; i++)
            a[i] = v[i];
        build(1,0,n-1);
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
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
    }
    T query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r);
        T p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
    void update (int node, int start, int end, int idx, int val){
        if (start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node,start,mid,idx,val);
        else 
            update(2*node  + 1,mid + 1, end,idx,val);
        
        tree[node] = merge(tree[2*node],tree[2*node + 1]);    
    }
};
int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1,0,n-1);
    cout << query (1,0,n-1,1,3) 
    update (1,0,n-1,n-1,5);
    cout << query (1,0,n-1,1,3);
}