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
    int t;
    cin >> t;
    while (t--){
        LL n,x;
        cin >> n >> x;
        LL a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        LL ans = 0;
        LL sum = 0;
        int j = -2;
        for(int i = 0; i < n; i++){
            if(j == -2 && a[i] >= x){
                j = i - 1;
            }
            if(a[i] >= x){
                ans ++;
                sum+= a[i];
            }
        }
        while(j >= 0){
            if ((sum + a[j]) >= (ans + 1) * x){
                ans ++;
                sum += a[j];
                j--;
            }else break;
        }
        cout << ans << endl;
    }
}