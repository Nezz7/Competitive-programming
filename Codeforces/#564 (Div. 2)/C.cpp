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
int p[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[x] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        p[i] = x;
        a[x] = i + 2;
    }
    int start = 1;
    bool cond = true;
    if (a[1])
        for(int i = a[1] - 2; i < n; i++){
            if(p[i] == start) start++;
            else {cond = false;break;}
        }
    if (cond == false){
        start = 1;
    }
    int ans = 0;
    cond = true;
    for (int i = start; i <= n; i++){
        ans++;
        if (a[i] > ans) cond = false;
    }
    if (cond){
        cout << ans << endl;
        return 0;
    }
    start = 1;
    ans = a[start];
    for (int i = start + 1; i <= n; i++){
        ans = max(ans + 1,a[i]);
    }
    cout << ans;
}