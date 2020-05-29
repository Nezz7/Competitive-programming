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
int min_pos[MAXN], max_pos[MAXN];
int used[MAXN];
vector<int> a,b;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, x;
    cin >> n >> x;
    int p;
    for(int i = 1; i <= x; i++) min_pos[i] = 1e9;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> p;
        v.pb(p);
        min_pos[p] = min(min_pos[p],i);
        max_pos[p] = i;
    }
    if(is_sorted(all(v))){
        cout << x * 1LL * (x + 1) / 2;
        return 0;
    }
    int pref = 1;
    int last = max_pos [1];
    a.pb(last);
    for(int i = 2; i <= x; i++){
        if(min_pos[i] == 1e9){
            a.pb(last);
            pref = i;
            continue;
        }
        if(last < min_pos[i]){
            pref = i;
            last = max_pos[i];
            a.pb(last);

        }else break;
    }
    int suf = x;
    last = min_pos[x];
    b.pb(last);
    for(int i = x - 1; i >= 1; i--){
        if(max_pos[i] == 0){
            suf = i;
            b.pb(last);
            continue;
        }
        if(max_pos[i] < last){
            suf = i;
            last = min_pos[i];
            b.pb(last);
        }else break;
    }
    reverse(all(b));
    LL ans = 1 + pref + x - suf + 1;
    int s = 1;
    for(auto x : a){
            auto it = upper_bound(all(b),x - 1) - b.begin();
            ans += sz(b) - it;
            s++;
            if(s == suf) break;
    }
    cout << ans << endl;

}