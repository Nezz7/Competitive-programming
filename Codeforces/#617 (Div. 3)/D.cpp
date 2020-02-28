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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        if (h % (a+b) == 0) v.push_back((b + a - 1)/ a);
        else if (h % (a+b) <= a) ans++;
        else v.push_back(((h % (a+b)) + a - 1)/a - 1);
    }
    sort (all(v));

    for (int i = 0; i < sz(v); i++){
        if(v[i] <= k) k -= v[i], ans++;
        else break;
    }
    cout << ans << endl;
    }