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
map<int,int> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        mp.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = 0;
        for(auto x : mp){
            int a = x.first;
            int s = x.second;
            auto it = mp.upper_bound(a);
            ans += s/a;
            if(it != mp.end()){
                mp[it->first] += s % a;
            }
        }
        cout << ans << endl;
    }
}