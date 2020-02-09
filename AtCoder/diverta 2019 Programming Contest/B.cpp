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
    LL r,g,b,n;
    LL ans  = 0;
    cin >> r >> g >> b >> n;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            LL x = r*i +j*g;
            if ( x >  n) continue;
            LL y = n - x;
            if (y % b == 0) ans++;
        }
    }
    cout << ans;
 }
