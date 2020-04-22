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
map<int,int> dp;
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int len = 0;
    int s = -1;
    for(int i = n - 1; i >= 0; i--){
        dp[a[i]] = dp[a[i] + 1] + 1;
        if(dp[a[i]] > len){
            len = dp[a[i]];
            s = a[i];
        }
    }
    cout << len << endl;
    for(int i = 0; i < n; i++){
        if(a[i] == s){
            cout << i + 1 << ' ';
            s++;
        }
    }
}