#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e5+ 9;
int a[MAXN],b[MAXN],exist[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        memset(exist,0,sizeof exist);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        for (int i = 0; i < m; i++){
            cin >> b[i];
            exist[b[i]] = -1;
        }
        LL ans = 0;
        int j  = 0;
        for (int i = 0; i < n; i++){
            if(j == m) break;
            if (b[j] == a[i]){
                exist[b[j]] = 2 * (i - j) + 1;
                while (j < m && exist[b[j]] != -1)
                    j++;
            }
            if (exist[a[i]] == -1) exist[a[i]] = 1;
        }
        for (int i = 0; i <= n; i++) ans+= exist[i];
        cout << ans << endl;
    }
}