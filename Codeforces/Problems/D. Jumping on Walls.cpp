#include <bits/stdc++.h>
using namespace std;
bool state[2][100005];
int main (){
    ios_base::sync_with_stdio(0);
    cin .tie(0), cout.tie(0);
    int n,k;
    cin >> n >> k;
    string g[2];
    cin >> g[0] >> g[1];
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    bool is_valid = false;
    int dist[2][n];
    memset(dist,-1,sizeof dist);
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if (y>=n){
            is_valid = true;
            break;
        }
        if (y < t) continue;
        if (g[x][y] == 'X') continue;
        if (dist[x][y]!=-1) continue;
        dist[x][y]= t;
        t++;
        q.push({{x,y+1},t});
        q.push({{x,y-1},t});
        q.push({{1-x,y+k},t});
    }
    if (is_valid) cout << "YES";
    else cout << "NO";
}
