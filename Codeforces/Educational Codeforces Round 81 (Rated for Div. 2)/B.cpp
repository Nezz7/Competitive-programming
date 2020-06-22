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
        int n,x;
        cin >> n >> x;
        string s;
        cin >> s;
        int sum = 0;
        bool cond = false;
        int ans = 0;
        int z,o;
        z = o = 0;
        for (auto c : s){
            z += (c == '0');
            o += (c == '1');
            sum = (z - o);
            if (sum == x) cond = true;
        }
        if (cond && sum == 0){
            cout << -1 << endl;
            continue;
        }
        if (!cond && sum == 0){
            cout << 0 << endl;
            continue;
        }
        z = o = 0;
        int cur = 0;
        for (auto c : s){
            z += (c == '0');
            o += (c == '1');
            cur = (z - o);
            if ((x - cur )% sum == 0 && (x - cur)/ sum >= 0) ans++;
        }
        if ( x == 0) ans++;
        cout << ans << endl;
    }
 }
