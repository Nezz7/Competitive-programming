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
    int n,m;
    cin >> n >> m;
    if( m == 1){
        cout << 2*n << endl;
        for(int i = 0; i < n; i++){
            cout << "D";
        }
         for(int i = 0; i < n; i++){
            cout << "U";
        }
        return 0;
    }
    if (n == 1){
        n = m;
        cout << 2*n << endl;
        for(int i = 0; i < n; i++){
            cout << "L";
        }
         for(int i = 0; i < n; i++){
            cout << "R";
        }
        return 0;
    }
    cout <<  n * m + n + m - 2 << endl;
    for (int i = 0; i < m - 1; i++){
        cout << "L";
    }
    for (int i = 0; i < n - 1; i++){
        cout << "U";
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if (i%2 == 0) cout << "R";
            else cout << "L";
        }
        cout << "D";
    }
}