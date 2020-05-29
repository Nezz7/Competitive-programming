#pragma GCC optimize ("O3")
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
int const MAXN = 1e7 + 9;
int h[3001][3001];
deque < pair <int,int> > dq;
deque < pair <int,int> > dq2[3001];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    LL g0, x, y, z;
    cin >> g0 >> x >> y >> z;
    LL last = g0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            h[i][j] = last;
            last = ((last * x) % z + y) % z;
        }
    }
    LL ans = 0;
    for(int j = 0; j < m; j++){
        dq.clear();
        for(int i = 0; i < n; i++){
            int cur2 = h[i][j];
            while(!dq2[i].empty() && dq2[i].back().first >= cur2) dq2[i].pop_back();
            dq2[i].emplace_back(cur2,j);
            if(dq2[i].front().second < j - b + 1) dq2[i].pop_front();
            int cur = dq2[i].front().first;
            while(!dq.empty() && dq.back().first >= cur) dq.pop_back();
            dq.emplace_back(cur,i);
            if(dq.front().second < i - a + 1 ) dq.pop_front();
            if(i >= a - 1 && j >= b - 1) ans += (LL) dq.front().first;
        }
    }
    cout << ans << endl;
}