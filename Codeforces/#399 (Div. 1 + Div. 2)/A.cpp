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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
         cin >> a[i];
    int mn = *min_element(a, a + n);
    int mx= *max_element(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans += (mn < a[i] && a[i] < mx);
    cout << ans;
}