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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    LL a,b;
    cin >> a >> b;
    LL ans = 1e9;
    for(LL i = 0; i < 5000; i++){
        for(LL j = 0; j < 5000; j++){
            if(i == j && i == 0) continue;
            if((a * i + b * j) % n == 0){
                ans = min(i + j, ans);
            }
        }
    }
    cout << ans << endl;
}