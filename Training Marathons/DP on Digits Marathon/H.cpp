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
bool ok (int x){
    int s = 0;
    while (x > 0){
        s+= x % 10;
        x/=10;
    }
    return s == 10;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int ans = 0;
    int k;
    cin >> k;
    while (k){
        ans++;
        if (ok(ans)) k--;
    }
    cout << ans << endl;
}