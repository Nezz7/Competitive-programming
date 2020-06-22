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
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a & 1) odd++;
            else even++;
        }
        bool cond = false;
        for(int i = 1; i <= x; i+=2){
            if(odd >= i && even >= x - i) cond = true;
        }
        if(cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}