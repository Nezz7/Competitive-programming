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
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        LL all = 0;
        for(int i = 1; i <= n; i++){
            a[i] = (1LL << i);
            all += a[i];
        }
        LL b = 0;
        for(int i = 1; i <n/2; i++){
            b += a[i];
        }
        b += a[n];
        LL x = all - b;
        cout << abs(b - x) << endl;
        
    }
}