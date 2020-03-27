#include <bits/stdc++.h>
#define f first
#define s second
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
int s[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    s[0] = 0;
    for(int i = 0; i <n ; i++){
        s[i+1] += s[i] + a[i]; 
        mp[s[i+1]]++;
    }
    int ans = 0;
    if(s[n]%3){
        cout << ans;
        return 0;
    }
    int x = s[n]/3;
    for(int i = 1; i <= n; i++){
            if(mp.count(s[i]+x) && mp.count(s[i]+2*x)) ans++;
    }
    cout << ans;
}