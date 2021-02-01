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
LL const inf = 1e11; 
LL a[MAXN];
LL need_car[MAXN], need_moto[MAXN], give_useless[MAXN], give_car[MAXN], give_moto[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, k;
    cin  >> n >> k;
    LL lc, pc, lm, pm;
    cin >> lc >> pc >> lm >> pm;
    LL t, d;
    cin >> t >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    
    for(int i = 0; i < n; i++){

        need_car[i + 1] += need_car[i];
        if(lc > a[i]){
            int diff = lc - a[i];
            if(diff > d) need_car[i + 1] += inf;
            else need_car[i + 1] += diff;
        }

        need_moto[i + 1] += need_moto[i];
        if(lm > a[i]){
            int diff = lm - a[i];
            if(diff > d) need_moto[i + 1] += inf;
            else need_moto[i + 1] += diff;
        }

        give_useless[i + 1] += give_useless[i] + a[i] - max(a[i] - d, 1LL);  

        give_car[i + 1] += give_car[i];
        if(a[i] > lc){
            give_car[i + 1] += a[i] - max(lc,a[i] - d);
        } 
      
        give_moto[i + 1] += give_moto[i];
        if(a[i] > lm){
            give_moto[i + 1] += a[i] - max(lm,a[i] - d);
        }
    }
    LL ans = inf;
    for(int x = 0; x <= n; x++){
        int y = max(n - x * k, 0LL);
        LL need = need_car[n] - need_car[n - x];
        need += need_moto[n - x] - need_moto[n - x - y];

        LL have = give_useless[n - x - y];
        have += give_moto[n - x] - give_moto[n - x - y];
        have += give_car[n] - give_car[n - x];

        if(have >= need){
            ans = min(ans, x * pc + y * pm + need * t);
        }
    }


    if(ans == inf) ans = -1;
    cout << ans << endl;

    
}