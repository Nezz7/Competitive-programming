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
int const MAXN = 1000 + 9;
int a[MAXN][MAXN], b[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    int n = h + x;
    int m = w + y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
            if(i < x) a[i][j] = b[i][j];
            else if(j < y) a[i][j] = b[i][j];
            else if(i < h && j < w) a[i][j] = b[i][j] - a[i - x][j - y];
        }
    }
     for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cout << a[i][j] <<  ' ';
        cout << endl;
     }
    
}