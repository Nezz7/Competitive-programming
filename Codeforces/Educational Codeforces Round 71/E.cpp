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
    cout << "? ";
    for(int i = 1; i <= 100; i++){
        cout << i  << ' ';
    }
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    int mx = (1<<7) - 1;
    LL ans =  x & (mx << 7);
    cout << "? ";
    for(int i = 1; i <= 100; i++){
        cout << (i << 7) << ' ';
    }
    cout << endl;
    cout.flush();
    cin >> x;
    ans |= (x & mx);
    cout << "! " << ans;
    cout << endl;
    cout.flush();
}