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
LL a [MAXN][MAXN];
LL b [MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int n,m;
        cin >> n >> m;
        LL ans  = 0;
        LL cur = 0;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j],cur += a[i][j];
                b[i][j] = a[i][j];
            }
        }
        while(true){
            ans += cur;
            bool cond = false;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    LL sum = 0;
                    LL cnt = 0;
                    for (int k = j - 1; k >= 0; k--){
                        if(a[i][k]){
                            sum += a[i][k];
                            cnt ++;
                            break;
                        }
                    }
                    for(int k = j + 1 ; k < m ; k++){
                        if(a[i][k]){
                            sum += a[i][k];
                            cnt ++;
                            break;
                        }
                    }
                    for (int k = i - 1; k >= 0; k--){
                        if(a[k][j]){
                            sum += a[k][j];
                            cnt ++;
                            break;
                        }
                    }
                    for(int k = i + 1 ; k < n ; k++){
                        if(a[k][j]){
                            sum += a[k][j];
                            cnt ++;
                            break;
                        }
                    }
                    if (a[i][j] && a[i][j] * cnt < sum){
                        cur -= a[i][j];
                        b[i][j] = 0;
                        cond = true;
                    }else b[i][j] = a[i][j];              
                }
            }
              for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) a[i][j] = b[i][j];
            if (!cond) break;
        }
        cout << "Case #"  << cc << ": ";
        cout << ans << endl;
    }
}