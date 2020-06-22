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
int n;
int a[MAXN];
int b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        int cond = true;
        int one = false;
        int mone = false;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        if (a[0] != b[0]) cond = false;
        if(a[0] == 1) one = true;
        if (a[0] == -1) mone = true;
        for (int i = 1; i < n; i++){
            if(a[i] > b[i] && !mone) cond = false;
            if(a[i] < b[i] && !one) cond = false;
            if(a[i] == 1) one = true;
            if (a[i] == -1) mone = true;
        }
        if (cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}