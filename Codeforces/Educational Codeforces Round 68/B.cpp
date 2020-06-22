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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        char a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        int row [n];
        int col [m];
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < m; j++)
                cur += (a[i][j] == '.');
            row[i] = cur;
        }
        for(int j = 0; j < m; j++){
            int cur = 0;
            for(int i = 0; i < n; i++)
                cur += (a[i][j] == '.');
            col[j] = cur;
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if (a[i][j] == '.') ans = min(ans,row[i] + col[j] - 1);
                else  ans = min(ans,row[i] + col[j]);
        }
        cout << ans << endl;
    }
}