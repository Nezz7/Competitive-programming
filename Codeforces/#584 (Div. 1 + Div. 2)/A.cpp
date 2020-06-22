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
int const MAXN = 1000+ 9;
int a[MAXN],used[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!used[a[i]]){
            ans++;
            for(int x = a[i]; x <= 100; x+=a[i]){
                used[x] = 1;
            }
        }
    }
    cout << ans << endl;
}