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
int get(int x){
    int nbr = x;
    int s = 0;
    while(nbr > 0){
        s += nbr % 10;
        nbr /= 10;
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int x;
    cin >> x;
   int ans = 1;
   while(x > 0){
       ans++;
       x -= get(x);
   }
   cout << ans << endl;
}