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
        int n;
        cin >> n;
        int a[5]={0,0,0,0,0};
        int cur = 0;
        int x = n;
        for (LL i = 2; i*i <= n; i++){
            if  (n % i == 0 && n > 1){
                    n/=i;
                    a[cur] = i;
                    cur++;
                if (cur == 2) break;
            }
            if (cur == 2) break;
        }
        if (n >= 2 && n != a[0] && n != a[1] && a[1] * a[0] * n == x){
            cout << "YES\n";
            cout << a[0] << " " << a[1] <<" " << n << endl;
        }else cout << "NO\n";
    }
 }
