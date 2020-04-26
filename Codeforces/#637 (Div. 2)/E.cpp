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
int const MAXN = 1e4 + 9;
int a[MAXN];
LL dist[MAXN][1050];
int g,r;
int n, m;
int total;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a,a+m);
    cin >> g >> r;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 1050; j++)
            dist[i][j] = 1e18;
    }
    total = g + r;
    dist[0][0] = 0;
    deque<pair<int,int>> q;
    q.push_back({0,0});
    while (!q.empty()){
        LL d = q.front().first;
        int idx = q.front().second;
        q.pop_front();
        int nxt =  idx + 1;
        int cur = a[nxt] - a[idx];
        if(nxt < m){
            if(cur + d < g && dist[nxt][cur+d] > dist[idx][d]){
                dist[nxt][cur+d] = dist[idx][d];
                q.push_front({cur+d,nxt});
            }
            if(cur + d == g && dist[nxt][0] > dist[idx][d]  + 1){
                dist[nxt][0] = dist[idx][d] + 1;
                q.push_back({0,nxt});
            }
        }
        nxt = idx - 1;
        if(nxt >= 0){
            cur = a[idx] - a[nxt];
            if(cur + d < g && dist[nxt][cur+d] > dist[idx][d]){
                dist[nxt][cur+d] = dist[idx][d];
                q.push_front({cur+d,nxt});
            }
            if(cur + d == g && dist[nxt][0] > dist[idx][d]  + 1){
                dist[nxt][0] = dist[idx][d] + 1;
                q.push_back({0,nxt});
            }
        }
    }
    LL ans = 1e18;
    for(int j = 0; j < m ; j++)
        for(int i = 0; i < g; i++){
            dist[j][0] = min(dist[j][0],dist[j][g]);
            if(dist[j][i] != 1e18 && n - a[j] + i<= g)
                ans = min(ans,dist[j][i] * total + i + n - a[j]);
    }
    if (ans == 1e18) ans =-1;
    cout << ans;
}   