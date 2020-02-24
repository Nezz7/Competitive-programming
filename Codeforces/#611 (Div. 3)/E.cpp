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
int x[MAXN],a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++){
        for (int j = -1; j < 2; j++)
            if (x[a[i]+ j] == 0){
                x[a[i]+ j] = 1;
                break;
        }
    }
    int mx = 0, mn = 1;
    int j = 0;
    for (int i = 0; i <= n + 1; i++) mx+= x[i];
    for (int i = 1; i < n ; i++){
        if (a[i] - a[j] > 2) j = i,mn++;
    }
    cout << mn << " " << mx << endl;
}