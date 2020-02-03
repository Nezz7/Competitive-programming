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
    int q;
    cin >> q;
    while (q--){
        LL a,b,x;
        cin >> a >> b >> x;
        if (x == 0) cout << b - a + 1 << endl;
        else
        if (x > b) cout << 0 << endl;
        else {
            int c = max(a,x);
            int cur = 0;
            LL ans = 0;
            LL p = 0;
            for (int i = 0; i < 62; i++){
                if (x & (1LL << i)) continue;
                LL bit = ((b & (1LL << i))>> i);
                LL bit2 = ((c & (1LL << i))>> i);
                ans |= (bit << cur);
                p |= (bit2 << cur);
                cur++;
            }

            cout << ans - p + ((a & x ) == x) + ((b & x ) == x) << endl;
        }

    }
 }
