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
 bool f (string a){
    int y = 0;
   int  x = 0;
    int b  = 0;
    for (int i = 0; i < sz(a); i++){
        b +=a[i]-48;
        if (a[i] == '0') y++;
        if (a[i]%2 == 0) x++;
    }
    if (b%3 != 0) return 0;
    if (y == 0) return 0;
    if (x == 1) return 0;
    return 1;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >>  s;
        cout << f(s) << endl;
    }
 }
