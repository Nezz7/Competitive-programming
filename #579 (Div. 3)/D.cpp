#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; i++){
        adj[s[i]-'a'].push_back(i);
    }
    int l[m],r[m];
    int last = adj[t[0]-'a'][0];
    l[0] = last;
    for (int i = 1; i < m; i++){
        l[i] = *(upper_bound(adj[t[i]-'a'].begin(),adj[t[i]-'a'].end(),last));
        last = l[i];
    }
    int x = adj[t[m-1]-'a'].size();
    last = adj[t[m-1]-'a'][x-1];
    r[m-1] = last;
    for (int i = m - 2; i >= 0; i--){
        auto it = lower_bound(adj[t[i]-'a'].begin(),adj[t[i]-'a'].end(),last);
        it--;
        r[i] = *it;
        last = r[i];
    }
    int ans = max(r[0],n - l[m-1] - 1 );
    for (int i = 0; i < m - 1; i++){
        ans = max(ans,r[i+1] - l[i] - 1);
    }
    cout << ans << endl;
}
