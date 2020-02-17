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
LL const MOD = 11092019;
vector<int> adj[26];
LL get (LL x){
    return (1 + x) * x / 2;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++){
        adj[s[i] - 'a'] . push_back(i);
    }  
    for (int i = 0; i < 26; i++) adj[i].pb(n);
    LL ans = 0;
    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';
        int x = *upper_bound(all(adj[c]),i);
        cout << x << endl;
        cout << " get = " << get(x  - i )  << endl;
        ans += (get(x - i) % MOD);
        ans %= MOD ;
    }
    cout << (ans  + 1) % MOD << endl;
}