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
 LL get(LL x){
    return x * ( x + 1) / 2;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    LL ans = 0;
    LL cnt = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x == 0){
            ans += get(cnt);
            cnt = 0;
        }else cnt++;
    }
        ans += get(cnt);
    cout << ans ;
 }
