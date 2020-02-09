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
 int c[102][102], g[102][102];
 void build (int x, int y){
    for (int i = x; i <= y; i ++){
        for (int j = x; j <= y; j++){
             if (i == j) continue;
             g[i][j] = 1;
             g[j][i] = 1;
        }
    }
 }
 int get (int n, int k){
    if (n == k or k == 0) return 1;
    int & ret = c[n][k];
    if (ret != -1) return ret;
    return ret = get(n - 1 ,k - 1) + get(n - 1,k);
 }
 int s[200];
 int main(){
ios_base::sync_with_stdio (0),cin.tie(0);

 }
