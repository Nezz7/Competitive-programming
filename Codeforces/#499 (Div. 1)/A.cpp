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
int n;
int m;
int a[MAXN], b[MAXN];
bool check(LD x){
    LD tot = x + m;
    LD need = tot/a[0];
    if(need > x) return false;
    x -= need;
    for(int i = 1; i < n; i++){
        tot = m + x;
        need = tot/b[i];
        if(need > x) return false;
        x -= need;
        tot = m + x;
        need = tot/a[i];
        if(need > x) return false;
        x -= need;
    }
    tot = x + m;
    need = tot/b[0];
    if(need > x) return false;
    return true;

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    LD ans = -1;
    LD low = 0, hi = 1e9 + 9;
    for(int i = 0; i < 200; i++){
        LD mid = (low + hi)/2.0;
        if(check(mid)){
            ans = mid;
            hi = mid;
        }else low = mid;
    }
    cout << setprecision(10) ;
    cout << ans << endl;
}