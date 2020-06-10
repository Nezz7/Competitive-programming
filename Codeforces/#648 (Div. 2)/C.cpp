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
int a[MAXN],b[MAXN], ans[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x] = i;
    }
    
    for(int j = 0; j < n; j++){
        int x;
        cin >> x;
        b[x] = j;
    }
    for(int i = 1; i <= n; i++){
        int c = ((a[i] - b[i]) % n + n ) % n;
        ans[c]++;
    }
    int mx = *max_element(ans, ans + MAXN);
    cout << mx << endl;
}