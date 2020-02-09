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
 LL d[MAXN];
 map<int,set<int>> mp;
 int n, m;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        LL u, v, x;
        cin >> u >> v >> x;
        d[v]+=x;
        d[u]-=x;
    }
    for (int i = 1; i <= n; i++){
        if (d[i] == 0) continue;
        mp[d[i]].insert(i);
    }
    for (int i = 0; i < n; i++) cout << d[i+1] << " ";
    cout << endl;
    vector<pair<pair<int,int>,LL> > edges;
    for (auto cur : mp ){
        if (cur.first < 0) continue;
        for (auto x : cur.second){
            auto it = mp[-cur.first].begin()
            if (mp[-cur.first])
            edges.push_back({{*it,x},cur.first});
            mp[-cur.first].erase(*it);
            mp[-cur.first]
        }
    }

    cout << edges.size() << endl;
    for (auto cur : edges){
        cout << cur.first.first << " " << cur.first.second << " " << cur.second << endl;
    }
 }
