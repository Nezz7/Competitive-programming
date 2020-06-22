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
int const MAXN = 50 + 9;
int a[MAXN][MAXN];
int dist[MAXN][MAXN];
int n, m;
bool valid(int x, int y){
    return x >= 0 && x < n &&  y >= 0 && y < m;
}
 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j],dist[i][j] = 1e8;
       
        queue<pair<int,int>> q;
    dist[0][0] = 0;
    q.push({0,0});
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(valid(i + 1, j) && dist[i + 1][j] > 1 + dist[i][j]){
             dist[i + 1][j] = 1 + dist[i][j];
             q.push({i + 1, j});
        }
        if(valid(i, j + 1) && dist[i ][j + 1] > 1 + dist[i][j]){
             dist[i][j + 1] = 1 + dist[i][j];
             q.push({i, j + 1});
        }
    }
    q.push({n - 1, m - 1});
    dist[n - 1][m -1] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(valid(i - 1, j) && dist[i - 1][j] > 1 + dist[i][j]){
             dist[i - 1][j] = 1 + dist[i][j];
             q.push({i - 1, j});
        }
        if(valid(i, j - 1) && dist[i ][j - 1] > 1 + dist[i][j]){
             dist[i][j - 1] = 1 + dist[i][j];
             q.push({i, j - 1});
        }
    }
    map<int,int> cnt;
    map<int,int> all;
    map<int,int> o;
    int mx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
                cnt[dist[i][j]]++,mx = max(mx,dist[i][j]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dist[i][j] == mx){
                    int go = 0;
                    if(valid(i - 1, j) && dist[i -1][j] == mx)  go++;
                    if(valid(i , j - 1) && dist[i][j - 1] == mx)  go++;
                    if(valid(i + 1, j) && dist[i + 1][j] == mx)  go++;
                    if(valid(i , j + 1) && dist[i][j + 1] == mx)  go++;
                    if(!go) continue;
                }
                
                    all[dist[i][j]]++;
                    o[dist[i][j]] += a[i][j];
            }
        }
 
        LL ans = 0;
        for(auto cur: all){
            int x = cur.first;
            int p = all[x];
            int one = o[x];
            int z = p - one;
            ans += min(one,z);
        }
        cout << ans  << endl;
    }
}