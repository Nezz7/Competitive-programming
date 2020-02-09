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
 map<int,vector<int>> adj;
 map<LL,LL> mp;
 vector<int> out;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n , k;
    cin >> n >> k;
    LL s = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
        adj[x].pb(i+1);
        s += x;
    }
    if (s < k){
        cout << -1;
        return 0;
    }
    if (s == k) return 0;
    LL last = 0;
    bool cond = false;
    bool c = false;
    int l = 0;
    vector<int> st;
    LL X;
    for (auto cur : mp){
        if (cond or k == 0){
            for (auto x : adj[cur.first]) out.pb(x);
            continue;
        }
        X= (cur.first - last);
        if (k >= X * n){
            k -= X*n;
            n-= cur.second;
            for (auto x : adj[cur.first]) st.pb(x);
        }else {
               int i = 1;
               sort(all(st));
               X--;
               int k1 = k;
               k %=n;
               for (auto x : adj[cur.first]){
                    auto it = lower_bound(all(st),x);
                    int p = it - st.begin();
                    if (k1 <  X*n + x - p){
                        out.pb(x);
                    }else l++;
               }
               cond = true;
        }
        last = cur.first;
    }
    sort(all(out));
    k-=l;
    int it = (k + sz(out)) % sz(out);
    for (int i = 0; i < sz(out); i++){
        cout << out[it] << " ";
        it++;
        it%=sz(out);
    }
 }
