#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
#define int LL
using namespace std;
int const MAXN = 2e6 + 9;
LL a[MAXN];
LL b[MAXN];
LL lazy[4*MAXN];
LL tree[4*MAXN];
LL const inf = 1e18;
vector<pair<pair<int,int>,int>> monster;
struct Lazy{
    #define T  LL
    int n;
    const T MYZERO = -1e18; //ZERO OF F
    Lazy(int sz){
        n = sz;
        build(1,0,n-1);
    }
    T merge(T x, T y){ // DEFINE
        return max(x,y);
    }
    void build (int node, int start, int end){
        if (start == end){
            tree[node] = b[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
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
        if(start > end or start > r or end < l or l > r)
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
signed main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < MAXN; i++) a[i] = b[i] = inf;
    int n,m,p;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++){
        int x,c;
        cin >> x >> c;
        a[x] = min(c,a[x]);
    }
    for(int i = 0; i < m; i++){
        int x,c;
        cin >> x >> c;
        b[x] = min(c,b[x]);
    }
    for(int i = MAXN -2; i >= 0; i--){
        a[i] = min(a[i + 1],a[i]);
        b[i] = min(b[i + 1],b[i]);
    }
    for(int i = 0; i < MAXN; i++) b[i] *= -1;
    for(int i = 0; i < p; i++){
        int x,y,z;
        cin >> x >> y >> z;
        monster.push_back({{x,y},z});
    }
    sort(all(monster));
    Lazy tree(MAXN);
    LL best = -a[0] + b[0];
    for(int i = 0; i < p; i++){
        int curA = monster[i].first.first;
        int curB = monster[i].first.second;
        int curZ = monster[i].second;
        LL curANS = -a[curA + 1];
        tree.update(curB + 1,MAXN - 1,curZ);
        curANS += tree.query(0,MAXN - 1);
        best = max(best,curANS);
    }
    cout << best << endl;
}