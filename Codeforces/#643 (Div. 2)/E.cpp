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
int b[MAXN];
LL pref[MAXN];
LL n, a, r, m;
LL check(LL x){
    LL greater = b + n - upper_bound(b, b + n, x);
    LL smaller = lower_bound(b, b + n, x) - b ;
    LL sg = pref[n] - pref[n - greater];
    LL ss = pref[smaller];
    LL cost = 0;
    if (a + r <= m){
        cost += r * (sg - x * greater);
        cost += a * (x * smaller - ss);
    }else {
        LL s1 = (sg - x * greater);
        LL s2 = (x * smaller - ss);
        if(s1 >= s2){
            cost += m * s2;
            s1 -= s2;
            cost += r * s1;
        }else {
            cost += m * s1;
            s2 -= s1;
            cost += a * s2;
        }
    }
    return cost;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> a >> r >> m;
    set<int> all;
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        all.insert(b[i]);
        mx = max(b[i],mx);
    }
    sort(b, b + n);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i + 1] = b[i] + pref[i];
    }
    LL ans = 1e18;
    LL low = 0, hi = 1e9;
    while((hi - low) > 3){
        int m1 = low + (hi - low)/3;
        int m2 = hi - (hi - low)/3;
        LL f1 = check(m1);
        LL f2 = check(m2);
        if(f1 >= f2){
            low = m1;
        }else hi = m2;
    }
    for(int x = low; x <= hi; x++)
        ans = min(ans,check(x));
    cout << ans << endl;
}