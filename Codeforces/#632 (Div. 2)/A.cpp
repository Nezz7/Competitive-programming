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
int const MAXN = 500 + 9;
char a[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                a[i][j] = 'B';
        }
        a[0][m-1] = 'W';
          for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cout << a[i][j];
            cout << endl;
        }
    }
}