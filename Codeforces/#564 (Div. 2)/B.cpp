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
    int n;
    cin >> n;
    cout << n / 2 + 1 << endl;
    int x = 1 , y = 1;
    for (int i = 0; i < n/2 + 1; i++){
        cout << x << ' ' << y + i << endl;
    }
    x = 2;
    y = n / 2 +1;
    for(int i = n/2 + 1; i < n; i++){
        cout << x << ' ' << y << endl;
        x++;
    } 
}