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
LL n, start,mx;
LL d[MAXN],h[MAXN];
bool check (LL x){
    x--;
    LL cur = start;
    cur -= mx;
    for(int i = 0; i < n; i++){
        if(cur + h[i] * x <= d[i] * x) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> start;
        LL dif = -1e9;
        for(int i = 0; i < n; i++){
            cin >> d[i] >> h[i];
            dif = max(d[i] - h[i],dif);
        }
        mx = *max_element(d,d + n);
        if(mx >= start) {
            cout << 1 << endl;
            continue;
        }
        if(dif <= 0){
            cout << -1  << endl;
            continue;
        }
        start -= mx;
        cout << (start + dif - 1) / dif  + 1<< endl;
    }
}