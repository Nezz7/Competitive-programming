#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = (1<<21);
int dist[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < (1 << 21); i++) dist[i] = 1e9;
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int ret = 0;
        for(int j = 0; j < sz(s); j++){
            if (s[j] == '1') ret |= (1 << j);
        }
        q.push(ret);
        dist[ret] = 0;
    }
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int bit = 0; bit < k; bit++){
            int j = (u ^ (1 << bit));
            if(dist[j] == 1e9){
                dist[j] = 1 + dist[u];
                q.push(j);
            }
        }
    }
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < (1 << k); i++){
        if(dist[i] > mx){
            mx = dist[i];
            ans = i;
        }
    }
    for(int i = 0; i < k; i++){
        cout << !!(ans & (1 << i));
    }
    
}