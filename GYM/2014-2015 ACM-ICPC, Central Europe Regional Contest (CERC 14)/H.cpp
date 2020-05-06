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
int const MAXN = 2e6 + 9;
int a[5][5];
int vis[MAXN];
bool go(int x, int y, int pos, vector<int> & d){
    if(x > 3 or y > 2) return false;
    if(pos == sz(d)) return true;
    while(pos < sz(d) && d[pos] == a[x][y]) pos++;
    return go(x,y+1,pos,d) or go(x+1,y,pos,d);
}
bool check (int x){
    if(vis[x] != -1) return vis[x];
    vector<int> d;
    while(x > 0){
        d.pb(x % 10);
        x/=10;
    }
    reverse(all(d));
    return vis[x] = go(0,0,0,d);
 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < 3; i++){
        for(int j  = 0; j < 3; j++){
            a[i][j] = 3 * i + (j + 1);
        }
    }
    a[3][0] = a[3][2] = -1;
    a[3][1] = 0;
    memset(vis,-1,sizeof (vis));
    for(int i = 0; i < 250; i++)
        check(i);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++){
            if(check(n - i)){
                cout << n - i  << endl;
                break;
            }else if(check(n + i)){
                cout << n + i  << endl;
                break;
            }
        }
    }
}