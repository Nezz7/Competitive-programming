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
        LL n, d;
        cin >> n >> d;
        vector<LL> v;
        bool cond  = false;
        for (LL i = 1; i * i <= d; i++){
            if ( i - 1 + (d+i-1)/i <= n) cond =true;
            LL x = d/i;
            if (x - 1 + (d + x - 1)/ x <= n) cond = true;
        }
        if(cond){
            cout << "YES\n";
        }else cout << "NO\n";
    }
 }
