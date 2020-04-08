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
int a[MAXN];
#define T pair<int,int> // Type
vector<T> tree;
struct SegTree{
    vector<int> a;
    const T MYZERO = {0,1e9}; //ZERO OF F
    int n;
    SegTree(vector<int>&v){
        n = v.size();
        a.assign(n, 0);
        tree.assign(4*n, {0,0});
        for(int i = 0; i < n; i++)
            a[i] = v[i];
        build(1,0,n-1);
    }
    T merge(T a, T b){ // DEFINE
        return {max(a.first,b.first),min(a.second,b.second)};
    }
    void build (int node, int start, int end){
        if (start == end){
            tree[node] = {a[start],a[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
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
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    vector<int> a (3*n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n; i < 3 * n; i++)
        a[i] = a[i - n];
    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    if (mn >= (mx + 1)/2){
        for (int i = 0; i < n; i++)
            cout << -1 << " ";
        return 0;
    }
    SegTree tr(a);
    int ans[3*n];
    for(int i = 3 * n - 1; i >=  0; i--){
        ans[i] = 0;
        int x = a[i];
        int l = i, r = 3*n -1;
        int j = 3* n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            int y = tr.query(i,mid).first;
            if(y  > x){
                j = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        int k = 3 * n - 1;
        l = i, r =3*n -1;
        while (l <= r){
            int mid = (l + r) / 2;
            int y = tr.query(i,mid).second;
            if(2 * y <  x){  
                k = mid;
                r = mid - 1 ;
            }else l = mid + 1;
        }
        if (j < k){
            ans[i] = ans[j] + j - i ; 
        }else ans[i] = k - i;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}