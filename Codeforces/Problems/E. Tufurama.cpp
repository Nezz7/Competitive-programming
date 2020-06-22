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
 int const MAXN = 2e6 + 9;
 int a[MAXN];
 vector<int> tree[4*MAXN];
 void build (int node, int start, int end){
    if (start == end){
        tree[node].push_back(a[start]);
        return ;
    }
    int mid = (start + end) / 2;
    build (2*node,start,mid);
    build (2*node + 1,mid+1,end);
    merge(all(tree[2*node]), all(tree[2*node+1]),back_inserter(tree[node]));
 }
 int query(int node, int start, int end, int l, int r, int k){
    if (end < l or  r < start) return 0;
    if (l <= start && end <= r) return tree[node].end() - lower_bound(all(tree[node]),k);
    int mid = (start + end) / 2;
    int p1  = query(2*node,start,mid,l,r,k);
    int p2  = query(2*node+1,mid+1,end,l,r,k);
    return p1 + p2;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL ans = 0;
    build(1,0,n-1);
    for (int i = 0; i < n ; i++){
        int x = query(1,0,n-1,0,a[i]-1,i+1);
        ans += x;
        if (a[i]>= i+1) ans--;
    }
    cout << ans/2;
 }
