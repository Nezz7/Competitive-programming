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
 int get (int x){
    int ret = 0;
    while (x > 0){
        int d = x % 10;
        x/=10;
        ret = ret * 10 + d;
    }
    return ret;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    //cout << get(110);
    for (int i = 0; i <= n ; i++){
        if (i + get(i) == n) cout << i << " " << get(i) << endl;
    }
 }
