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
    int T;
    cin >> T;
    while (T--){
        int a[3];
        cin >> a[0] >> a[1]>> a[2];
        sort(a,a+3);
        int x = a[0], y =a[1], z = a[2];
        int ans = 0;
        for (int i = 0; i <= min(a[0],1); i++)
            for (int j = 0; j <= min(a[1],1); j++)
                for (int k = 0; k <= min(a[2],1); k++){
                    if (i == j && j == k && k == 0) continue;
                    if (i <= x && j <= y && k <= z){
                        //cout << i << " " << j<< " " << k << endl;
                        ans++;
                        x-=i;
                        y-=j;
                        z-=k;
                    }
                }
    cout << ans << endl;
    }
}