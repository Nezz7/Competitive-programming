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
int msb (LL x){
    for (int i = 60; i >= 0; i--)
        if (x & (1LL << i)) return i;
    return -1;
}
LL a,b,x;
LL get (LL a, LL msk){
   if ( a < 0) return 0;
   if ( a == 0) return 1;

   if (msk <= a) return (1LL << (__builtin_popcountll(msk)));

   LL p = ( 1LL << (63 - __builtin_clzll(msk)));
   return get(a - p, msk - p) + get(a, msk - p);
} 

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int q;
    cin >> q;
    while (q--){
        cin >> a >> b >> x;
        LL msk = x ^ ((1LL << 61)- 1);
        cout <<get(b - x ,msk) - get(a- x - 1, msk)<< endl;

    }
}