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
int pos[MAXN],q[MAXN];
struct Lazy{
    #define T int //DEFINE
    vector<T> lazy;
    vector<T> tree;
    const int MYZERO = 0; //ZERO OF F
    Lazy (int n){
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    T merge(T a, T b){ // DEFINE
        return max(a,b);
    }

    void propagate(int node, int start, int end){
            if(lazy[node] != 0){ 
                tree[node] += lazy[node];  // This node needs to be updated 
            if(start != end){
                lazy[node*2] += lazy[node];                 
                lazy[node*2+1] += lazy[node];                
            }
            lazy[node] = 0;                                  
        }
    }
    void add(int node, int start, int end, int l, int r, int val){
        propagate(node,start,end);
        if(start > end or start > r or end < l)              
            return;
        if(start >= l and end <= r){
            lazy[node] = val;
            propagate(node,start,end);
            return;
        }
        int mid = (start + end) / 2;
        add(2*node, start, mid, l, r, val);        
        add(2*node + 1, mid + 1, end, l, r, val);  
        tree[node] = merge(tree[2*node],tree[2*node+1]);        
    }

    T getMax(int node, int start, int end, int l, int r){
        if(start > end or start > r or end < l)
            return MYZERO;         
        propagate(node,start,end);
        if(start >= l and end <= r)            
            return tree[node];
        int mid = (start + end) / 2;
        T p1 = getMax(node*2, start, mid, l, r);       
        T p2 = getMax(node*2 + 1, mid + 1, end, l, r); 
        return merge(p1 , p2);
    }
};


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> q[i],q[i]--;
    Lazy tree(n+1);
    int ans = n;
    tree.add(1,0,n-1,0,pos[ans],+1);
    for (int i = 0; i < n ; i++){
        cout << ans << " ";
        tree.add(1,0,n-1,0,q[i],-1);
        while(tree.getMax(1,0,n-1,0,n-1) <= 0){
            ans --;
            tree.add(1,0,n-1,0,pos[ans],+1);
        }
    }
}