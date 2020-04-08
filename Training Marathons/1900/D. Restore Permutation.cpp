#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
struct Lazy{
    #define T pair<LL,LL> //DEFINE
    vector<LL> lazy;
    vector<T> tree;
    vector<LL> a;
    int n;
    const T MYZERO = {1e16,0}; //ZERO OF F
    Lazy(vector<LL>&v){
        n = v.size();
        a.assign(n, 0);
        tree.assign(4*n, {0,0});
        lazy.assign(4*n, 0);;
        for(int i = 0; i < n; i++)
            a[i] = v[i];
        build(1,0,n-1);
    }
    T merge(T x, T y){ // DEFINE
        return min(x,y);
    }
    void build (int node, int start, int end){
        if (start == end){
            tree[node] = {a[start],-start};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
    }
    void propagate(int node, int start, int end){
            if(lazy[node] != 0){ 
                tree[node].first += lazy[node];  // This node needs to be updated 
            if(start != end){
                lazy[node*2] += lazy[node];                 
                lazy[node*2+1] += lazy[node];                
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

int main(){
   // ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int ans[n];
    vector<LL> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    Lazy tree(v);
    for (int i = 0; i < n; i++){
        int mn = -tree.query(0,n-1).second;
        ans[mn] = i + 1;
        tree.update(mn,n-1,-(i+1));
        tree.update(mn,mn,1e11);
    }
    for (auto cur : ans) cout << cur << ' ';
}