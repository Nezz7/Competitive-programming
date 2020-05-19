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
int n,m,dp[MAXN],a[11];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    while(cin >> n){
        memset(dp,0,sizeof(dp));
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            bool win = false;
            for(int j = 0; j < m; j++){
                if ( i - a[j] >= 0 && dp[i - a[j]] == 0) win = true;
            }
            dp[i] = win;
        }
        if(dp[n]) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
}