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
int pref[MAXN];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        pref[0] = 0;
        for(int i = 0; i <= n + 5; i++) pref[i] = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i < n - 1; i++){
            if(a[i] > a[i -1] && a[i] > a[i + 1]) {
                pref[i + 1]++;
            }
        }
        for(int i = 1; i <= n + 2; i++){
            pref[i] += pref[i - 1];
        }
        int mx = -1;
        int ans = 0;
        for(int i = 0; i < n - k + 1; i++){
            int r = i + k - 1;
            int cur = pref[r] - pref[i + 1];
            if (cur > mx){
                mx = cur;
                ans = i;
            }
        }
        cout << mx + 1<< ' ' << ans +1 << endl;
    }
}