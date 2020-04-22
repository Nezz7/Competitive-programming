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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;
    int ans = 0;
    int cur = 0;
    while(k--){
        int x;
        cin >> x;
        for(int i = x; i <= n; i+=x){
            if(!a[i]){
                a[i] = 1;
                cur++;
            }else {
                a[i] = 0;
                cur--;
            }
        }
        ans = max(cur,ans);
    }
    cout << ans ;
}