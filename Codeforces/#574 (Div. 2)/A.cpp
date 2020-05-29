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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    int odd = 0, even = 0;
    for(int i = 0; i <= k; i++){
        if(a[i]){
            odd += (a[i] % 2);
            even += (a[i] / 2);
        }
    }
    int have = (n + 1)/2;
    int ans  = 0;
    if(have >= even){
        have -= even;
        ans = 2 * even;
    }else {
        ans = 2 * have;
        have = 0;
    }
    ans += min(have,odd);
    cout << ans << endl;
}