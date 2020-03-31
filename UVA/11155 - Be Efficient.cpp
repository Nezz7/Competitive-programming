#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
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
    int cas = 0;
    while(T--){
        cas++;
        int a,b,c,m,n;
        cin >> a >> b >> c >> m >> n;
        LL x[n];
        LL s[n];
        s[0] = a;
        x[0] = a;
        for(int i = 1; i < n; i++){
            x[i] = (x[i - 1] * b + c) % m + 1;
            s[i] = s[i-1] + x[i];
        }
        LL ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int cur = s[i] % m;
            ans += mp[cur];
            if(cur == 0) ans++;
            mp[cur] ++;
        }
        cout << "Case "<< cas << ": " << ans << endl;
    }

}