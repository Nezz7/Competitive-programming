struct Lazy{
    #define T int //DEFINE
    vector<T> lazy;
    vector<T> tree;
    vector<T> a;
    int n;
    const int MYZERO = 0; //ZERO OF F
    Lazy (int sz){
        n = sz;
        a.assign(sz, 0);
        tree.assign(4*sz, 0);
        lazy.assign(4*sz, 0);
    }
    Lazy(vector<int>&v){
        n = v.size();
        Lazy(n);
        for(int i = 0; i < n; i++)
            a[i] = v[i];
        build(1,0,n-1);
    }
    T merge(T a, T b){ // DEFINE
        return max(a,b);
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
    void propagate(int node, int start, int end){
            if(lazy[node] != 0){ 
                tree[node] += (end - start + 1) * lazy[node];  // This node needs to be updated 
            if(start != end){
                lazy[node*2] += lazy[node];                 
                lazy[node*2+1] += lazy[node];                
            }
            lazy[node] = 0;                                  
        }
    }
    void update(int l, int r,int val){
        update(1,0,n-1,l,r,val);
    }
    void update(int node, int start, int end, int l, int r, int val){
        propagate(node,start,end);
        if(start > end or start > r or end < l)              
            return;
        if(start >= l and end <= r){
            lazy[node] = val;
            propagate(node,start,end);
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r, val);        
        update(2*node + 1, mid + 1, end, l, r, val);  
        tree[node] = merge(tree[2*node],tree[2*node+1]);        
    }
    T query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    T query(int node, int start, int end, int l, int r){
        if(start > end or start > r or end < l)
            return MYZERO;         
        propagate(node,start,end);
        if(start >= l and end <= r)            
            return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(node*2, start, mid, l, r);       
        T p2 = query(node*2 + 1, mid + 1, end, l, r); 
        return merge(p1 , p2);
    }
};
