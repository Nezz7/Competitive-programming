 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " = " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 LL get (LL x){
    LL ret = x;
    for (LL i = 2; i * i <= x; i++){
        if (x % i == 0) ret -= ret/i;
        while (x % i == 0) x/= i;
    }
    if (x != 1) ret -= ret / x;
    return ret;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL a,b;
        cin >> a >> b;
        LL g = __gcd(a,b);
        b/=g;
        cout << get(b) << endl;
    }
 }
