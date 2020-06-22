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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int x = 0;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int last = 0;
        for(LL i = 2; i < MAXN; i++){
            LL x = i * (i - 1) / 2;
            if( x <= n) last = i;
            else break; 
        }
        n-= last * (last - 1) / 2;
        if(n){
            cout << 133;
            last -= 2;
        }else cout << 1;
        string out = string(n,'7') + string(max(last,0),'3');
        out += '7';
        cout << out << endl;
    }*/
}