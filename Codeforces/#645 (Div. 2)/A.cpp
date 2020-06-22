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
        LL a, b;
        cin >> a >> b;
        cout << (a * b + 1) / 2 << endl;
    }
}
1 2 4 7 11
3 5 8 12 17
6 9 13 18 24
10 14 19 25
15 20 26 31


1 1 1 1 1 
1 2 3 4 5 
1 3 5 7 9 
1 4 7 10 13 
1 5 12 21 26 
