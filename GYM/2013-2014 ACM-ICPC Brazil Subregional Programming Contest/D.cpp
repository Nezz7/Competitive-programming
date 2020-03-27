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
map<deque<int>,bool> vis;
void solve(deque<int> v){
   /* for(auto cur : v) cout << cur <<" ";
    cout << endl;*/
    vis[v] = true;
    int n = v.size();
    for(int i = 0; i < n; i++){
        deque<int> a;
        for(int j = 0; j < i ; j++) a.pb(v[j]);
        int l = sz(a) - 1;
        for(int j = i; j < n; j++){
            if ( l >= 0) a[l] += v[j];
            else a.push_front(v[j]);
            l--;
        }
        if(vis.count(a) == 0)
        solve(a);
    }
    reverse(all(v));
    if(vis.count(v) == 0)
        solve(v);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    deque<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.pb(x);
    }
    deque<int> res;
    int m;
    cin >> m;
    for(int i = 0; i < m;i++){
        int x;
        cin >> x;
        res.pb(x);
    }
    solve(v);
    if(vis.count(res)){
        cout << "S";
    }else cout << "N";
}