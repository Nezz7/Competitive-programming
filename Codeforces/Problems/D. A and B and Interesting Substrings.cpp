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
 LL sum[MAXN],a[26],nxt[MAXN];
 vector<pair<LL,LL>> adj[26];
int cc = 0;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int i = 0;
    sum[i] = 0;
    for (auto c : s){
        sum[i + 1] = sum[i] + a[c-'a'];
        adj[c - 'a'].push_back({sum[i+1],i});
        i++;
    }
    LL ans = 0;
    for (int i = 0; i < 26; i++){
        sort(all(adj[i]));
        for (auto cur : adj[i]){
             auto it = upper_bound(all(adj[i]),make_pair(cur.first+a[i],cur.second));
             auto it2 = lower_bound(all(adj[i]),make_pair(cur.first+a[i]+1,0LL));
             if (it != adj[i].end() && it -> first - cur . first == a[i]){
                ans += it2- it;
             }
        }
    }
    cout << ans << endl;
 }
