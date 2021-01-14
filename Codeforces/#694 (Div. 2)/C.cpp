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
LL a[MAXN], b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        LL ans = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int j = 0; j < m; j++)
            cin >> b[j];
        sort(a, a + n);
        reverse(a, a + n);
        int ind = 0;
        for(int i = 0; i < n; i++){
            if(ind < m && b[a[i] - 1] <= b[ind]){
                ans += b[a[i] - 1];
            }else {
                ans += b[ind];
                ind++;
            }
        }
        cout << ans << endl;
    }
}