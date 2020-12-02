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
int sum[MAXN];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    if (n > 60){
        return cout << 1 , 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ a[i - 1];
    int ans = MAXN;
    for(int l = 0; l < n ; l++){
        for(int k = l; k < n; k++){
            for(int r = k + 1; r < n; r++){
                int x = sum[k + 1] ^ sum[l];
                int y = sum[r + 1] ^ sum[k + 1];
                if(y < x) ans = min(ans, r - l - 1);
            }
        }
    }
    if(ans == MAXN) ans = -1;
    cout << ans << endl;
}