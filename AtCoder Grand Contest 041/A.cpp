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
    LL n,a,b;
    cin >> n >> a >> b;
    LL d = abs(a-b);
    if (d % 2 ==0){
        cout << d /2;
        return 0;
    }
    LL p1 = a  ;
    LL p2 = n - b + 1;
    cout << min(p1,p2) + (b - a - 1 )/ 2;
 }
