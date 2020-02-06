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
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort (a,a+n);
        int x = a[0];
        int y = a[n-1];
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int p = abs(a[i] - a[j]);
                int p1 = abs (a[i] - x) + abs(a[j] - y);
                int mn = min (p1,p);
                if (mn == 3) cout << i << " " << j << endl;
                ans = max(ans,mn);
            }
        }
        cout << ans << endl;
    }
}