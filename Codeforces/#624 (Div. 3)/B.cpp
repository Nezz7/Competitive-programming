#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m ;
        int a[n],p[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> p[i];
        sort(p,p+m);
        int start = 0;
        int cur = 1;
        for (int i = 1; i < m; i++){
            if (p[i] == (p[start] + i - start)) cur++;
            else {
                sort(a+p[start]-1,a+p[start] + cur);
                start = i;
                cur = 1;
            }
        }
        sort(a+p[start]-1,a+p[start]+cur);
        if (is_sorted(a,a+n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}