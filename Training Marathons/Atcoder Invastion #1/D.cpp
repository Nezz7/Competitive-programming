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
int l[MAXN],r[MAXN];
LL dp[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            for (int k = 0; k < 100; k++){
            for (int c = 0; c < 100; c++){
                int f = i * j + i;
                int s = k - c * j;
                int th = j + k + j ;
                if (  f == 28 &&  s == 2 && th == 62){
                    cout << i << ' ' << j << ' ' << k << ' ' << c << endl;
                }
            }
            }
        }
    }
}