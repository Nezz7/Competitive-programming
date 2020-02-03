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
        LL a,b,c,n;
        cin >> a >> b >> c >> n;
        LL mx  = max({a,b,c});
        n -= (mx - a);
        n -= (mx - b);
        n -= (mx - c);
        if (n < 0 or n % 3){
            cout << "NO\n";
        }else cout << "YES\n";
    }
 }
