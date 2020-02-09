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
 int const MAXN = 1e3+5;
 LL const mod = 1e9+7;
 int a[MAXN][MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool cond = true;
    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        for (int j = 0; j < r; j++)
             if (a[i][j] == 0 or a[i][j] == 1) a[i][j] = 1;
            else cond = false;
         if(r < m){
         if (a[i][r] == 0 or a[i][r] == 2)  a[i][r] = 2;
            else cond = false;
         }
    }
    for (int j = 0; j < m; j++){
        int c;
        cin >> c;
        for (int i = 0; i < c; i++)
            if (a[i][j] == 0 or a[i][j] == 1) a[i][j] = 1;
            else cond = false;
        if (c < n){
        if (a[c][j] == 0 or a[c][j] == 2)
            a[c][j] = 2;
        else cond = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
                ans+=(a[i][j] == 0);
        }
    }
    LL p = 1;
    if (cond == false) return cout << 0, 0;
    for (int i = 0; i < ans; i++)
        p = (p * 2LL)% mod;
    cout << p << endl;
 }
