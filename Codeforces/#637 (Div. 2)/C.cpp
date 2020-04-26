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
int p[MAXN];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n + 5; i++) a[i] = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            p[x] = i + 1;
        }
        a[p[1]] = 1;
        bool cond = true;
        for(int i = 2; i <= n; i++){
            int x = p[i - 1] + 1;
            if (x <= n && !a[x] && x != p[i]) cond = false;
            a[p[i]] = 1;
        }
        if(cond) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}