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
    LL a,b;
    cin >> a >> b;
    LL ans = 0;
    for (LL i = a; i <= b; i++){
        for (LL j = 1; j*j <= i; j++){
            if (i%j == 0){
                    ans += j;
                    LL x = i/j;
                    if (x != j) ans+= x; 
            }
        }
    }
    cout << ans << endl;
}