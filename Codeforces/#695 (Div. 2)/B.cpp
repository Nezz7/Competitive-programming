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
int a[MAXN], dp[MAXN];
int n;
bool check (int i){
    if(i - 1 < 0 or i + 1 >= n) return false;
    if(a[i - 1] > a[i] && a[i] < a[i + 1]) return true;
    if(a[i - 1] < a[i] && a[i] > a[i + 1]) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            dp[i] = 0;
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += check(i);
        }
        int d = 0;
        for(int i = 1; i < n - 1; i++){
            int last = a[i];
            int have = check(i - 1) + check(i) + check(i + 1);
            a[i] = a[i - 1];
            int p1 = have - (check(i - 1) + check(i) + check(i + 1));
            a[i] = a[i + 1];
            int p2 =  have - (check(i - 1) + check(i) + check(i + 1));
            a[i] = last;
            d = max(d, max(p1,p2));
        }
        cout << ans - d << endl;
        
    }
}