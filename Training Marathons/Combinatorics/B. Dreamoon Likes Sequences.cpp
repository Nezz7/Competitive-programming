#include <bits/stdc++.h>
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
LL d, m;
LL mul (LL a, LL b){
    a %= m;
    b %= m;
    return  (a * b) % m;
}
LL sub(LL a, LL b){
    return ((a - b) % m + m) % m;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> d >> m;
        LL ans = 1;
        for(int i = 0; i < 31; i++){
            LL a = (1LL << (i + 1)) -1;
            LL b = (1LL << i);
            ans = mul (ans,sub(sub(min(a,d),b),-2));
            if(a >= d) break;
        }
        ans = sub(ans,1);
        cout << ans << endl;
    }
}