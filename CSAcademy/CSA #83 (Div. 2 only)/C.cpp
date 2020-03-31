#include <bits/stdc++.h>
#define f first
#define s second
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cur = 0;
    double ans = 0;
    double r = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == -1) cur += 2;
        if(a[i] == 1) cur -= 2;
        if(a[i] == 0) cur -= 1;
        if (cur < 0){
            if(cur == -1 && a[i] == 1) r+= 0.5;
            ans = max(ans,r);
            cur = 0;
            r = 0;
        }else r++;
    }
    ans = max(ans,r);
    cout << ans;

}