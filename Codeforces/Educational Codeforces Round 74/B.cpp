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
    int t;
    cin >> t;
    while(t--){
        int n,r;
        cin >> n >> r;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int ans = 0;
        int cur = a[n - 1] + 1;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] < cur && a[i] - ans * r > 0){
                    cur = a[i];
                    ans++;
            }
        }
        cout << ans << endl;
    }

}