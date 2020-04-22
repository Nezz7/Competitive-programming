#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e5 + 9;
pair<int,int> tree[1<<6][4*MAXN];
int a[MAXN][6];
int n, k;
struct SegTree{
    #define T pair<int,int>
    const T MYZERO = {-1e9,1e9}; //ZERO OF F
    int n;
    SegTree(int sz){
        n = sz;
        for(int i = 0; i < (1 << k); i++)
            build(1,0,n-1,i);
    }
    T merge(T a, T b){ // DEFINE
        return {max(a.first,b.first),min(a.second,b.second)};
    }
    void build (int node, int start, int end,int i){
        if (start == end){
            LL cur = 0;
            for(int j = 0; j < k; j++){
                if(i & (1 << j)) cur+= a[start][j];
                else cur -= a[start][j];
            }            
            tree[i][node] = {cur,cur};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node,start,mid,i);
        build(2*node+1,mid+1,end,i);
        tree[i][node] = merge(tree[i][2*node],tree[i][2*node +1]);
    }
    T query ( int l, int r,int i){
        return query (1,0, n -1 ,l,r, i) ;
     }
    T query (int node, int start, int end, int l, int r,int i){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return tree[i][node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r,i);
        T p2 = query(2*node+1,mid+1,end,l,r,i);
        return merge(p1,p2);
    }
    void update (int node, int start, int end, int idx, int val,int i){
        if (start == end){
            LL cur = 0;
            for(int j = 0; j < k; j++){
                if(i & (1 << j)) cur+= a[start][j];
                else cur -= a[start][j];
            }       
            tree[i][node] = {cur,cur};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node,start,mid,idx,val,i);
        else 
            update(2*node  + 1,mid + 1, end,idx,val,i);
        
        tree[i][node] = merge(tree[i][2*node],tree[i][2*node +1]);    
    }
    void update (int idx, int val,int i){
        update(1,0,n-1,idx,val,i);
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
            cin >> a[i][j];
    }
    int q;
    cin >> q;
    SegTree tree(n);
    while(q--){
        int t;
        cin >> t;
        if ( t == 1){
            int idx;
            cin >> idx;
            idx--;
            for(int i = 0; i < k; i++){
                int val;
                cin >> a[idx][i];
            }
            for(int i = 0; i < (1 << k) ; i++)
                tree.update(idx,0,i);
        }else {
            int l,r;
            cin >> l >> r;
            l--,r--;
            LL ans = -1e18;
            for (int i = 0; i < (1 << k); i++){
                auto cur = tree.query(l,r,i);
                ans = max(ans, (LL)abs(cur.first-cur.second));
            }
            cout << ans << endl;
        }
    }
}