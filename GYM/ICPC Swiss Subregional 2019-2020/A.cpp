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
LL a[100];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < 6; i++)
        cin >> a[i];
    sort(a, a + 6);
    LL r = min(a[1] - a[0], a[5] - a[4]);
    bool cond = false;
    for(int i = 1; i < 6; i++){
        if(a[i] - a[i - 1] == 2*r && r){
            cout << a[i - 1] + r << endl;
            cond = true;
        }
    }
    if(cond == false){
        if(a[0] - r > 0)
            cout << a[0] - r << endl;
        if(r != 0) 
            cout << a[5] + r << endl;
    }
}