#include <bits/stdc++.h>
#define LL long long int
using namespace std;
map<char,LL> mp;
LL mod = 1e9+7;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL mx = 0;
    for (auto c : s){
        mp [c]++;
        mx = max(mp[c],mx);
    }
    LL ans = 1;
    LL cnt = 0;
    for (auto cur : mp){
        if (cur.second == mx) cnt ++;
    }
    while (n--){
        ans = (ans * cnt)%mod;
    }
    cout << ans ;
}
