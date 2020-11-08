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
int n;
int const MAXN = 2e6 + 9;
int a[MAXN], b[MAXN];
bool check(int x){
    LL sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= x) continue;
        sum += b[i];
    }
    return sum <= x;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        int ans = 0;
        int low = 0, hi = 1e9;
        while(low <= hi){
            int mid = (low + hi + 1)/ 2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        cout << ans << endl;

    }
}