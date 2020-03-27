#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = MAXN + 9;
struct SegTree{
    vector<int> a;
    vector<pair<int,int>> tree;
    const int MYZERO = 0; //DEFINE
    SegTree(vector<int>&v){
        int n = v.size();
        a.assign(n, 0);
        tree.assign(4*n,{0,0});
        for(int i = 0; i < n; i++)
            a[i] = v[i];
        build(1,0,n-1);
    }
    pair<int,int> merge(pair<int,int> a, pair<int,int> b){ // DEFINE
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
    pair<int,int> query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return {0,1e9};
        if (l <= start  && end <= r) return tree[node];
        int mid = (start + end) / 2;
        pair<int,int> p1 = query(2*node,start,mid,l,r);
        pair<int,int> p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> p(n);            
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        p[v[i]] = i;
    }
    SegTree atree(v);
    SegTree ptree(p);
    int q;
    cin >> q;
    map<pair<int,int>,pair<int,int>> res;
    vector<pair<int,int>> go;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int mn,mx,l1=l,r1=r;
        do{
            l = l1, r = r1;
            go.pb({l,r});
            if(res.count({l,r})){
                for(auto cur : go){
                    res[cur] = res[{l,r}];
                }
                go.clear();
                l = res[{l1,r1}].first;
                r = res[{l1,r1}].second;
                break;
            }
            auto x  = atree.query(1,0,n-1,l,r);
            mn = x.second;
            mx = x.first;
            auto y = ptree.query(1,0,n-1,mn,mx);
            l1 = y.second;
            r1 = y.first;
        }while(l1 != l or r1 != r);
           for(auto cur : go){
                    res[cur] = {l,r};
            }
            go.clear();

        cout << l1 + 1 << " " << r1 + 1 << endl;
    }
}