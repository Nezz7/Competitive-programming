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
int mx[MAXN];
int mn[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n];
        for (int i  = 1; i <= n ; i++){
            mn[i] = 1e9;
            mx[i] = 0;
        }
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mn[a[i]] = min(mn[a[i]],i);
            mx[a[i]] = max(mx[a[i]],i);
        }
        bool cond = false;
        for (int i = 1; i <= n; i++){
            if (mx[i] - mn[i] >= 2) cond = true;
        }
        if(cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}