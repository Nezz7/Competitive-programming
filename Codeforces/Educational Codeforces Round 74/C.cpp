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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int h, n;
        cin >> h >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        a[n] = 0;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(a[i] == 1) break;
            //cout << a[i] << ' ';
            if(a[i] - 1 != a[i + 1]){
                ans++;
            }else i++;
        }
        cout << ans << endl;
    }
}