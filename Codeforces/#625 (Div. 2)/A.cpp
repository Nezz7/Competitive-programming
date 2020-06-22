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
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i],sum+=a[i];
    int b[n];
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    bool cond = true;
    int s = 0;
    int p = 0;
    int c = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]) cond = false;
        if (a[i] == b[i] && a[i] == 1) s++;
        if (a[i] == 1 && b[i] == 0) p ++;
        if (b[i] == 1 && a[i] == 0 ) c++;
    }
    if (cond or !p){
        cout << -1 << endl;
        return 0;
    }
    c++;
    cout << (c + p - 1) / p << endl;


    
}