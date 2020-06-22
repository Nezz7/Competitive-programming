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
    int n;
    cin >> n;
    while (n--){
        LL a,b,c,d;
        cin >> a >> b>> c >> d;
        if (a > b) swap(a,b);
        LL l = max(c-d,a);
        LL r = min(c+d,b);
        if (l>=a && l <= b && a <= r && r <= b)
        cout << b - a - (r - l) << endl;
        else cout << b - a << endl;
    }
 }
