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
    int r,s, p;
    cin >> r >> s >> p;
    for (int i = 0; i < p; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        a[i] =  (r - x) ;
        if(y < s) a[i] += s - y;
        else a[i] += y - s +1; 
    }
    sort(a,a+p);
    int ans = a[0];
    for(int i = 1; i < p; i++){
        if(a[i] <= ans){
            ans++;
            a[i] = ans;
        }
        ans = max(ans,a[i]);
    }
    cout << ans;
}