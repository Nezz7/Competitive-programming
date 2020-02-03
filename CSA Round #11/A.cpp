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
 int sum[MAXN];
 bool get (int x){
    int p = x % 10;
    x/=10;
    while (x > 0){
        int d = x % 10;
        x/=10;
        if (d!= p) return false;
    }
    return true;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for (int i = 1; i < MAXN; i++){
         sum[i] = sum[i-1] + get(i);
    }
    int a,b;
    cin >> a >> b;
    cout << sum[b] - sum[a-1];
 }
