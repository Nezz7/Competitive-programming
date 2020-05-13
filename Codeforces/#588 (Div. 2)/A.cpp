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
int a[5];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a,a+4);
    if(a[0] + a[3] == a[2] + a[1] or a[1] + a[0] + a[2] == a[3]){
        cout << "YES";
    }else cout << "NO";
}