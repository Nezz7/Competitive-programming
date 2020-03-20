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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if ( n == 1){
            cout << -1 << endl;
            continue;
        }
        if ( (n  - 1) * 5 % 3 ){
            for (int i = 0; i < n-1; i++) cout <<5;
            cout << 3;
            cout << endl;
            continue;
        }
        for (int i = 0; i < n-2; i++) cout <<5;
            cout << 33;
            cout << endl;
    }
}