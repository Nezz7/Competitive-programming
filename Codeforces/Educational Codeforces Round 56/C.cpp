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
    LL a[n];
    int last = 0;
    LL b[n];
    for(int i = 0; i < n/2; i++){
        cin >> b[i];
    }
    LL cur = 1e18;
    LL mn = 0;    
    for(int i = 0; i < n/2; i++){
        if(b[i] <= cur){
            a[n - 1 - last] = b[i] - mn;
            a[last] = mn;
            cur  = a[n - 1 - last];
            last ++;
        }else{
            if(b[i] - cur >= mn){
                a[n - 1 - last] = cur ;
                a[last] = b[i] - cur;
                mn = max(a[last],mn);
                last ++;
            }else {
                a[n - 1 - last] = b[i] - mn ;
                a[last] = mn;
                cur = a[n- 1 - last];
                last ++;
            }
        }
    }
    for(auto x : a){
        cout << x <<' ';
    }
}