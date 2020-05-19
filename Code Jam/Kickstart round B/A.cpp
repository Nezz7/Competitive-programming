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
void solve(int t){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cnt = 1;
        }else if(cnt && a[i] - a[i - 1] == -1){
            cnt++;
        }else cnt = 0;
        if(cnt == k) ans++;
    }
    cout << "Case #"<< t <<": " <<  ans << endl; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}