#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    pair<int,int> a[m];
    int ans[m];
    for (int i = 0; i < m; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    int last[m + 1];
    int cur = 1;
    memset(last,0,sizeof last);
    for(int i = m -1; i >= 0 ; i--){
        if ( i == m -1)
        last[i] = cur + a[i].first - 1;
        else last[i] = last[i + 1] + 1; 
    }
    int x = n - last[0];
    bool cond = true;
    for(int i = 0; i < m; i++){
        if(a[i].first > 1 && x > 0){
            int d = x - (a[i].first - 1);
            if ( d < 0) d = x;
            x-= d;
            last[i] += d;
        }
    }
    for(int i = 0; i < m; i++){
        ans[i] =  last[i] - a[i].first + 1;
    }
    if (ans[m - 1] == 1){
        for (int i = 1; i < m ; i++){
            int r = ans[i] + a[i].first - 1;
            if (r < ans[i  - 1] - 1) {
                cout << -1; return 0;
            }
        }
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
    }else cout << -1;
    

}