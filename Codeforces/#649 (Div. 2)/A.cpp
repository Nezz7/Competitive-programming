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
int const MAXN = 2e6 + 9;
int tree[4*MAXN];
struct SegTree{
    #define T int // Type
    const T MYZERO =  1e9;
    int n;
    SegTree(int sz){
        n = sz;
    }
    T merge(T a, T b){ // DEFINE
        return min(a,b);
    }
 
    T query ( int l, int r){
        return query (1,0, n -1 ,l,r) ;
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
        
        tree[node] = merge(tree[2*node], tree[2*node + 1]);    
    }
    void update (int idx, int val){
        update(1, 0, n - 1, idx, val);
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i = 0; i < MAXN; i++) tree[i] = 1e9;
        LL sum = 0;
        SegTree a(x);
        int ans = -1;
        for(int i = 0; i < n; i++){
            int b;
            cin >> b;
            sum += b;
            if(sum % x){
                ans = max(ans, i + 1);
            }
            int last = a.query(sum % x, sum % x);
            a.update(sum % x,1e9);
            int get = a.query(0,x);
            if(get != 1e9){
                ans = max(i - get , ans);
            }
            if(last == 1e9) a.update(sum % x,i);
            else a.update(sum % x,last);
        }
        cout<< ans << endl;
    }
}