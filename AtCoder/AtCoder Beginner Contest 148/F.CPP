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
 int f (int i){
    int p = 10;
    cout << i % p << endl;
    while (i % p ==0) p*=10,cout <<p<<endl;
    cout << p/10;
    return p/10;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int ret = 0;
    cout << f(2120);
   /* for (int i = 0; i <= n ;i++)
        ret += f(i);
    cout << ret;*/
 }

