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
        int n , m;
        cin >> n >> m;
        int a[n][m];
        map<int,int> mp[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >>a[i][j], mp[i][a[i][j]]++;
        LL ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j <m; j++){
                ans += min(mp[i][a[i][j]],mp[i-1][a[i][j]]);
                mp[i-1][a[i][j]] = 0;
            }
        cout << ans << endl;
    }
 }
