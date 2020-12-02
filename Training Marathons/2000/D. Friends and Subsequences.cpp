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
int treeA[4*MAXN], tree[4*MAXN], a[MAXN], b[MAXN];
struct SegTreeMax{
    #define T int // Type
    const T MYZERO = -2e9; //ZERO OF F
    int n;
    SegTreeMax(int sz){
        n = sz;
        build(1, 0, n - 1);
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
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }
    T query (int l, int r){
        return query (1, 0, n -1, l, r);
     }
    T query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r);
        T p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
};
struct SegTreeMin{
    #define T int // Type
    const T MYZERO = 2e9; //ZERO OF F
    int n;
    SegTreeMin(int sz){
        n = sz;
        build(1, 0, n - 1);
    }
    T merge(T a, T b){ // DEFINE
        return min(a,b);
    }
    void build (int node, int start, int end){
        if (start == end){
            treeA[node] = b[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
        treeA[node] = merge(treeA[2*node], treeA[2*node + 1]);
    }
    T query (int l, int r){
        return query (1, 0, n -1, l, r) ;
     }
    T query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return treeA[node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r);
        T p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
};

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    SegTreeMax treeMax(n);
    SegTreeMin treeMin(n);
    LL ans = 0;
    for(int i = 0; i < n; i++){
        int low = i, hi = n - 1;
        int upper_bound = -1;
        while(low <= hi){
            int mid = (low + hi)/2;
            if(treeMax.query(i, mid) > treeMin.query(i, mid)){
                upper_bound = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        int lower_bound = -1;
        low = i, hi = n - 1;
        while(low <= hi){
            int mid = (low + hi)/2;
            if(treeMax.query(i, mid) < treeMin.query(i, mid)){
                lower_bound = mid;
                low = mid + 1;
            }else hi = mid - 1;
        }
        if(lower_bound == -1 && upper_bound == -1){
            ans += n - i;
            continue;
        }
        if(lower_bound == -1){
            ans += upper_bound - i;
            continue;
        }
        if(upper_bound == -1){
            ans += n - 1 - lower_bound;
            continue;
        }
        ans += upper_bound - lower_bound - 1;
    }
    cout << ans  << endl;
}