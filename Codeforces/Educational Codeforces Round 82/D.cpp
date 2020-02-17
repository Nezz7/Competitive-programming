#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
map<LL,int> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL x, n;
        cin >> x >> n;
        LL sum = 0;
        mp.clear();
        for  (int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[(LL)a]++;
            sum += a;
        }
        LL ans = 0;
        for (int i = 0; i < 61; i++){
            LL bit = (1LL << i);
            if (bit & x){
                if (mp.count(bit)){
                    x &= (~(bit));
                    mp[bit]--;
                }else {
                    auto cur = mp.upper_bound(bit);
                    if (cur == mp.end()) break;
                    mp[cur-> first ] --;
                    if (mp[cur->first] == 0){
                        mp.erase(cur->first);
                    }
                    LL y = cur->first;
                    x &= (~(bit));
                    while (y != bit){
                        y/= 2;
                        mp[y]++;
                        ans++;
                    }
                }
            }
            if (mp[bit] / 2)
            mp[bit * 2LL] += mp[bit] / 2;
        }
        if (x == 0) cout << ans << endl;
        else cout << -1 << endl;

    }
}