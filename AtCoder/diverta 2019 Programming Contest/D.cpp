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
    LL n;
    cin >> n;
    LL ans = 0;
    vector<LL> div;
    for (LL i  = 1; i * i <= n; i++){
        if (n % i == 0){
            div.pb(i);
            LL x = n / i;
            if (x != i) div.pb(x);
        }
    }
    for (auto c : div){
        LL m = (n - c) / c;

        if (m && n/m == n % m) ans+= m;
    }
    cout << ans;
 }
