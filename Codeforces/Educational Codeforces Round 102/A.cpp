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
    int T;
    cin >> T;
    while(T--){
        int n, d;
        cin >> n >> d;
        
        for(int i = 0; i < n; i++)
            cin >> a[i];
        bool cond = false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] + a[j] <= d) cond = true;
            }
        }
        int mx = *max_element(a, a + n);
        if(mx <= d) cond = true;
        if(cond) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}