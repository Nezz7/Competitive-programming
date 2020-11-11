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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x, y, z;
        bool found = false;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i * 3 + j * 5 > n) break;
                if((n - i * 3 - j * 5) % 7 == 0){
                    found = true;
                    x = i;
                    y = j;
                    z = (n - i * 3 - j * 5)/7;
                    break;
                }
            }
        }
        if(found)
            cout << x << " " << y << " " << z << endl;
        else cout << -1 << endl;
    }
}