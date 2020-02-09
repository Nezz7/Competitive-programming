#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[2050];
long long res[2050];
 
long long sm(long long l, long long r){
    if(!l) return r * (r + 1) / 2;
    return r * (r + 1) / 2 - (l - 1) * l / 2;
}
long long get(long long l, long long r){
    if(l > r) return 0;
    return (r - l + 1) * 1LL * r - sm(l, r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s, t;
    cin >> n >> s >> t;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    long long tot = 0, mn = 2e18, mx = -1;
    for(int i = 0 ; i < n ; ++i){
        set < pair < int, int > > in;
        map < int, int > idx;
        for(int j = 0 ; j < n ; ++j){
            in.insert({a[j], idx[a[j]]});
            idx[a[j]]++;
        }
        long long sm = 0;
        int pos = a[i];
        while((int)in.size()){
            auto it = in.upper_bound({pos, -1});
            if(it == in.end()){
                sm += s - pos;
                pos = 0;
                continue;
            }
            in.erase(it);
            int nxt = it->first;
            sm += t + nxt - pos;
            pos = (nxt + t) % s;
        }
        mn = min(mn, sm);
        mx = max(mx, sm);
        res[i] = sm;
    }
    int p = -1;
    for(int i = 0 ; i < n ; ++i){
        tot += get(p + 1, a[i]) + (a[i] - p) * 1LL * res[i];
        if(p != a[i]) mx = max(mx, res[i] + a[i] - p - 1);
        p = a[i];
    }
    if(a[n - 1] != s - 1) tot += get(a[n - 1] + 1, s) + (s - 1 - a[n - 1]) * 1LL * res[0];
    long long g = __gcd(tot, 1LL * s);
    cout << mn << '\n' << mx << ' ' << '\n' << tot / g << '/' << s / g << '\n';
    return 0;
}