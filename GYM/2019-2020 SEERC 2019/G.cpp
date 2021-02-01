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
int const MAXN = 100 + 9;
char a[MAXN][MAXN],b[MAXN][MAXN];
vector<int> y[MAXN], z[MAXN];
set<int> yy[MAXN], zz[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j] -= '0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < h; j++){
            cin >> b[i][j];
            b[i][j] -= '0';
        }
    }
    vector<tuple<int,int,int>> maxi;
    vector<tuple<int,int,int>> mini;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int  k = 0; k < h; k++){
                if(a[i][j]  && b[i][k]){
                    maxi.push_back({i,j,k});
                }
                if(a[i][j] && yy[i].count(j) == 0) yy[i].insert(j),y[i].push_back(j);
                if(b[i][k] && zz[i].count(k) == 0) zz[i].insert(k),z[i].push_back(k); 
            }
        }
    }
    bool cond = true;
    for(int i = 0; i < n; i++){
        sort(all(y[i]));
        sort(all(z[i]));
        if(sz(y[i]) == 0 && sz(z[i]) == 0) continue;
        if(sz(z[i]) == 0){
            cond = false;
            break;
        }
        if(sz(y[i]) == 0){
            cond = false;
            break;
        }
        if(sz(y[i]) < sz(z[i])){
            int d = sz(z[i]) - sz(y[i]);
            for(int j = 0; j < d; j++){
                mini.push_back({i,y[i][0], z[i][j]});
            }
            for(int j = d; j < sz(z[i]); j++){
                mini.push_back({i,y[i][j - d], z[i][j]});
            }
        }else {
            int d = sz(y[i]) - sz(z[i]);
            for(int j = 0; j < d; j++){
                mini.push_back({i,y[i][j], z[i][0]});
            }
            for(int j = d; j < sz(y[i]); j++){
                mini.push_back({i,y[i][j], z[i][j -d]});
            }
        }
    }
    sort(all(maxi));
    sort(all(mini));
    if(!cond){
        cout << -1 << endl;
        return 0;
    }
    cout << maxi.size() << endl;
    for(auto cur : maxi){
        cout << get<0> (cur) << " " << get<1> (cur) << " "<< get<2> (cur) << endl;
    }
    cout << mini.size() << endl;
    for(auto cur : mini){
        cout << get<0> (cur) << " " << get<1> (cur) << " "<< get<2> (cur) << endl;
    }
}