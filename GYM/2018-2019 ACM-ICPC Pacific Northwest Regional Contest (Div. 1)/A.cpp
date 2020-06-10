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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int k;
    cin >> k;
    string a,b;
    cin >> a >> b;
    int same = 0, not_same = 0;
    for(int i = 0; i < sz(a); i++){
        same += (a[i] == b[i]);
        not_same += (a[i] != b[i]);
    }
    int ans = min(same,k);
    k -= ans;
    ans += not_same - k;
    cout << ans << endl;
}