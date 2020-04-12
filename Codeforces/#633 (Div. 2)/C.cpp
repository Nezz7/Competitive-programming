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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = -1;
        int mx = a[0];
        for(int i = 1; i < n; i++){
            if (a[i] >= mx){
                mx = a[i];
                continue;
            }
            int d = mx  - a[i];
            int l = -1, r = -1;
            for(int j = 0; j < 60; j++){
                if(d & (1LL << j)){
                    l = j;
                    break;
                }
            }
            for(int j = 60; j >= 0; j--){
                if(d & (1LL << j)){
                    r = j;
                    break;
                }
            }
            ans = max(r,ans);
        }
        
        cout << ans + 1 << endl;
    }
}x