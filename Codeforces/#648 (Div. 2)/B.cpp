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
int a[MAXN], b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool one = false, zero = false;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i]) one = true;
            else zero = true;
        }
        if(one && zero) cout << "YES"<< endl;
        else {
            bool cond = true;
            for(int i = 1; i < n; i++){
                if(a[i - 1] > a[i] ) cond = false;
            }
            if(cond) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}