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
    int n, s;
    cin >> n >> s;
    if(n * 2 > s){
        cout << "NO";
        return 0;
    }
    cout << "YES"<< endl;
    for(int i = 0; i < n - 1; i ++) cout << 2 << ' ';
    cout << s - (n - 1)*2 << endl;
    cout << 1 << endl;
}