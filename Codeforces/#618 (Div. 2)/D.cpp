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
LL x[MAXN],y[MAXN];
LL dist (int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j])  + (y[i] - y[j]) * (y[i] - y[j]);
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <n; i++){
        cin >> x[i] >> y[i];
    }
    if (n&1){
        cout << "NO";
        return 0;
    }
    bool cond = true;
    int a = n - 1;
    int b = n/2 - 1 ;
    int j = n/2;
    for (int i = 0; i < n/2 - 1;i++){
        int c = j + i;
        if (dist(i,a) != dist(c,b)) cond = false;
        if (dist(i,b) != dist(c,a)) cond = false;
        if (!cond) break;
    }
    if (cond) cout << "YES";
    else cout << "NO";
}