#include <bits/stdc++.h>
#define f first
#define s second
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
LD fast (int a,int b){
    if (b == 0) return 0;
    LD x = fast(a,b/2);
    if (b & 1){
        return log10(a) + x + x;
    }
    return x + x;

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int x;
    int i = 0;
    while( cin >> x){
        i++;
        cout <<"Case #"<< i <<": "<<(LL) fast(2,x) << endl;;
    }
}