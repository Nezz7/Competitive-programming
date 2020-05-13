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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int maxi = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(cur < 0) cur = 0;
        if(!a[i]) cur++;
        else cur --;
        maxi = max(cur,maxi);
    }
    int mini = 0;
    cur = 0;
    for(int i = 0; i < n; i++){
        if(cur > 0) cur = 0;
        if(!a[i]) cur++;
        else cur --;
        mini = min(cur,mini);
    }
    cout << maxi - mini + 1 << endl;
}