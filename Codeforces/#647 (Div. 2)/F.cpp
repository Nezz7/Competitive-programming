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
int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL p = 1;
    for(int i = 0; i < 100; i++)
    p = (p * 5) % mod;
    cout << p  + 26<< endl;
}