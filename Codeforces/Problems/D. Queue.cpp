#include <bits/stdc++.h>
using namespace std;
int const MAXN = 4e5+99;
vector<int> v;
int dp[MAXN];
int tree[4*MAXN];
int a[MAXN];
int m;
int query (int node, int start, int end, int l, int r){
    if (end < l or r < start) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) /2;
    int q1= query(2*node, start, mid, l, r);
    int q2= query(2*node+1, mid+1, end, l, r);
    return max(q1,q2);
}
void update (int node, int start, int end, int id, int val){
    if (start == end){
        dp[id] = max(val,dp[id]);
        tree[node] = max(val,dp[id]);
        return ;
      }
      int mid = (start + end) /2;
      if (start <= id && id <= mid)
            update(2*node, start, mid, id, val);
      else
            update(2*node + 1, mid+1, end, id, val);
    tree[node] = max(tree[2*node],tree[2*node + 1]);
}
int get (int x){
    int r = lower_bound(v.begin(),v.end(),x) - v.begin();
    return query(1,0,m,0,r);
}
void go (int x, int i){
    int id = upper_bound(v.begin(),v.end(),x) - v.begin();
    update (1,0,m,id,i);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++){
        int x;
        cin >> x;
        a[i] = x;
        v.push_back(x + 1);
        v.push_back(x);
        v.push_back(x - 1);
    }
    sort(v.begin(),v.end());
    m = v.size() - 1;
    int ans[n];
    for (int i = n - 1; i >= 0 ; i--){
        int p = get (a[i]);
        if (p == 0) ans [i] = -1;
        else ans[i] = p - i - 1 ;
        go(a[i],i);
    }
    for (int cur : ans) cout << cur << " ";
}
