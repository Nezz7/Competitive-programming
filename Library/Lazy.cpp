#define T  //DEFINE
LL lazy[4*MAXN];
T tree[4*MAXN];
struct Lazy{
    int n;
    const T MYZERO = ; //ZERO OF F
    Lazy(int sz){
        n = sz;
        build(1,0,n-1);
    }
    T merge(T x, T y){ // DEFINE
        return 
    }
    void build (int node, int start, int end){
        lazy[node] = 0;
        if (start == end){
            tree[node] =  // DEFINE
            return;
        }
        int mid = (start + end) / 2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
    }
    void propagate(int node, int start, int end){
            if(lazy[node] != 0){ 
                tree[node]   // This node needs to be updated 
            if(start != end){
                lazy[node*2]                 
                lazy[node*2+1]                
            }
            lazy[node] = 0;                                  
        }
    }
    void update(int l, int r,LL val){
        update(1,0,n-1,l,r,val);
    }
    void update(int node, int start, int end, int l, int r, LL val){
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