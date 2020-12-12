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
int a[600][600];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                a[i][j] = c == '*';
                if(j) a[i][j] += a[i][j- 1];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cur = a[i][j];
                if(j - 1 >= 0) cur -= a[i][j - 1];
                if(cur){
                    ans ++;
                    for(int k = i + 1, len = 1; k < n; k++, len++){
                        if(j - len < 0 or j + len >= m) break;
                        int tot = a[k][j + len];
                        if(j - len - 1 >= 0) tot -= a[k][j - len - 1];
                        if(tot == 2*len +1) ans++;
                        else break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}