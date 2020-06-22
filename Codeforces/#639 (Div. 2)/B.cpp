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
LL a[MAXN];
LL get(int x){
    return x * (x + 1) / 2;
}
LL solve (int n){
    auto it = upper_bound(a,a+25821,n) - a;
    it--;
    if(a[it] == 0) return 0;
    return 1 + solve(n - a[it]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    a[0] = 0;
    for(int i = 1; i < 25821; i++){
        a[i] = get(i - 1) * 3 + i * 2;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    
}