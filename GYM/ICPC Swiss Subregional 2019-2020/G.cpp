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
LD dp[33][100][33][100][33];
int n;
int a[33];

LD solve(int i, int s1, int n1, int s2, int n2){
    if(i == n){
        int s3 = 100 - s1 - s2;
        int n3 = n - s1 - s2;
        if(n3 == 0) return 1e9;
        LD a1 = s1/(LD) n1;
        LD a2 = s2/(LD) n2;
        LD a3 = s3/(LD) n3;
        return (a1 + a2 + a3)/(LD) 3;
    }
    LD & ret = dp[i][s1][n1][s2][n2];
    if(ret != -1) return ret;
    return ret = min(solve(i + 1, s1 + a[i], n1 + 1, s2, n2), min(solve(i + 1, s1, n1, s2, n2), solve(i + 1, s1, n1, s2 + a[i], n2 + 1)));
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

}