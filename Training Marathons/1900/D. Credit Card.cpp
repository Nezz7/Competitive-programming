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
LL maxi[MAXN];
LL pref[MAXN];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,d;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i] = a[i];
        if(i)
            pref[i] += pref[i-1];
    }
    maxi[n-1] = pref[n-1];
    for(int i = n-2; i>= 0;i--)
        maxi[i]= max(maxi[i+1],pref[i]);
    int cur = 0, ans = 0;;
    for(int i = 0; i < n; i++){
        if(pref[i] + cur > d)
            return puts("-1");
        if(a[i] == 0 && pref[i] + cur < 0){
            int x = d - (maxi[i]+cur);
            if(pref[i] + cur + x < 0)
                return puts("-1");
            cur += x;
            ans++;
        }
    }
    cout << ans << '\n';
}