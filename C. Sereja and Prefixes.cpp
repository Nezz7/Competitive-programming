#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL const MAXN = 1e5+9;
vector<LL> v;
vector<pair<pair<LL,LL>,LL>>inv;
LL sum[MAXN];
LL get(LL x){
    LL mx = 1e9;
    LL id = (upper_bound(inv.begin(),inv.end(),make_pair(make_pair(x,mx),0LL))) - inv.begin();
    id --;
    if (id  < 0 ) return v[x];
    if (inv[id].first.first <= x && x <= inv[id].first.second){
        x -= inv[id].first.first;
        x %= inv[id].second;
        return get(x);
    }
    x -= sum[id+1];
    return v[x];
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n;
    cin >> n;
    LL r = 0;
    while (n--){
        LL t;
        cin >> t;
        if (t == 1){
            LL x;
            cin >> x;
            v.push_back(x);
            r++;
        }else {
            LL l, c;
            cin >> l >> c;
            inv.push_back({{r,r+l*c -1},l});
            r = r+l*c;
        }
    }
    LL i = 1;
    for (auto cur : inv){
        sum[i] = sum[i-1] + cur.first.second - cur.first.first + 1;
        i++;
    }
    LL q;
    cin >> q;
    while (q--){
        LL x;
        cin >> x;
        x--;
        cout << get(x) << " ";
    }
}
