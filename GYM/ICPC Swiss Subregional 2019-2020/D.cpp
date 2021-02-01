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
int a[MAXN];
string yes ="Phew", no = "Lie";
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]) cnt++;
    }
    if(cnt == 0) cout << yes << endl;
    else if(cnt > 1)  cout << no << endl;
    else {
        if(a[n - 1] <= a[0]) cout << yes << endl;
        else cout << no << endl;
    }
}