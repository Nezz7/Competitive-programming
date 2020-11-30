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
int const MAXN = 3e7 + 9;
int const MAXn = 3e4 + 9;
int p[MAXN];
LL c[MAXn], out[MAXN];
vector<int> g[MAXn];
void sieve(){
    p[1] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!p[i]){
            for(int j = i ; j < MAXN; j += i)
                p[j] = i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    /*int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 0; i < k; i++){
        int u, v, x;
        cin >> u >> v >> x;
        g[v].pb(u);
    }*/
    sieve();
    vector<int> primes;
    for(int i = 2; i < MAXN; i++){
        if(p[i] == i) primes.push_back(i);
    }
    for(int i = 0; i <10; i++) cout << primes[i] << " ";
    cout << endl;
    cout << primes.size() << endl;
}
