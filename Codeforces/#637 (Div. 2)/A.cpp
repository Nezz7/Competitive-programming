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
        int n;
        int a,b,c,d;
        cin >> n >> a >> b >> c >> d;
        bool cond = false;
        for(int i  = c - d; i <= c + d; i++){
            int l = (a - b) * n;
            int r = (a + b) * n;
            int x = i / n;
            if ( l <= i && i <= r) cond = true;
            
        }
        if(cond) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}