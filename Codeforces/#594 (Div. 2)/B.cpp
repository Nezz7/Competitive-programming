#include <bits/stdc++.h>
#define f first
#define s second
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
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    LL x  = 0, y = 0;
    LL x1 = 0, y1 = 0;
    int r = n -1, l = 0;
    int r1 = n -1, l1 = 0;
    for (int i = 0; i < n; i++){
        if ( i % 2) x+= a[r], y1 += a[l1],r--,l1++;
        else y+= a[l], x1 += a[r1],l++,r1--;
    }
    cout << max(x*x + y*y, x1*x1 + y1*y1);
}