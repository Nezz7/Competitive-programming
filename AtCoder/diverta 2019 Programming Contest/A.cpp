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
int n, k;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    LL ans = 0;
    for (int i = 1; i <= n; i++){
         if (i  + k  - 1<= n) ans++;
    }
     cout << ans;
 }
