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
 int const MAXN = 1e7 + 9;
 int const MOD = 1e9+7;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    LL d = 1;
    LL a = 0;
    for (int i = 0; i < n; i++){
        LL xd = (a * 3) % MOD;
        LL xa = (d + a * 2) % MOD;
        d = xd;
        a = xa;
    }
    cout << d;


 }
