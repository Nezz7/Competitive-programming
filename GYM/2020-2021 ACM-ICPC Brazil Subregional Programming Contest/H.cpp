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
LL a[100];
LL C[100][100]; 
void binomialCoeff(int n, int k) { 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
}
int n, k;
LL get(int i, int k, LL x){
    LL ret = 0;
    if(k == 0) return 1;
    if(i == n) return 0;
    if(a[i] > x) return get(i + 1, k, x);
    return get(i + 1, k - 1, x - a[i]) + C[n - i - 1][k];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    binomialCoeff(50, 50);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    LL l, r;
    cin >> l >> r;
    cout << get(0, k , r) - get(0, k, l - 1) << endl;
}