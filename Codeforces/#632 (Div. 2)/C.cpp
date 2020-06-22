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
map<LL,int> mp;
map<LL,int> mp2;
LL a[MAXN];
LL pref[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int i = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){
        pref[i + 1] = pref[i + 2] + a[i];
    }
    LL s = 0;
    LL ans = 0;
    mp[0] = 0;
    int last =0;
    int last2 = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 0){
            last = i + 1;  mp[s] = i+ 1;
            mp2[pref[i+1]] = i+1;
            continue;
        }
        s+= a[i];
        LL x = (i + 1 - max(mp2[pref[i+2]],max(last,last2)));
        last2 = max(mp2[pref[i+2]],max(last,last2));
        ans += x;
        mp2[pref[i+1]] = i+1;
        mp[s] = i+ 1;
    }
    cout << ans;

   
}