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
int n, k;
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k; 
        for(int i = 0; i < n; i++)  cin >> a[i];
        LL ans = 1e15;
        LL out  = 0;
        for(int i = 0; i + k < n; i++){
            LL mid = (a[i] +  a[i + k]) / 2;
            LL cur = max(mid - a[i],a[i + k] - mid);
            if(cur < ans){
                ans = cur;
                out = mid;
            }
        }
       cout << out << endl;
    }
}