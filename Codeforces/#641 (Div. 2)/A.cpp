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
LL f[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 2; i < MAXN; i++){
        for(int j = i; j < MAXN; j+= i){
            if(!f[j]) f[j] = i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        LL n, k;
        cin >> n >> k;
        if(n % 2 && k){
            k--;
            n += f[n];
        }
        if(n % 2 == 0 && k){
            n += 2 * k;
        }
        cout << n << endl;
    }
}