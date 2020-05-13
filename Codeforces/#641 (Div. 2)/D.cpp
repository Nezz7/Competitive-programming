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
bool solve(){
    int n,k;
    cin >> n >> k;
    bool cond = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == k) cond = true;
        a[i] = (a[i] >= k)? 1 : -1;
    }
    if(!cond) return false;
    if(n == 1) return true;
    for(int i = 0; i < n - 1; i++)
        if(a[i] + a[i + 1] == 2) return true;
    for(int i = 0; i < n - 2; i++)
        if(a[i] + a[i + 1] + a[i + 2] == 1) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
      if(solve()) cout << "yes" << endl;
      else cout << "no" << endl;
    }
}