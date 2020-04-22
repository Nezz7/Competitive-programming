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
int dp[100];
LL get(int i,int k){
    if ( k % 3 ) return (i%3 !=0);
    int cycle = k + 1;
    i %= cycle;
    if(i == cycle -1) return 1;
    return (i % 3 != 0);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << (get(n,k)? "Alice" : "Bob") << endl;
    }
   
}