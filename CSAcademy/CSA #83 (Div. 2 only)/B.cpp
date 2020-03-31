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
LL get(LL l, LL r){
    if(l > r) return 0;
    LL n = (r - l) + 1;
    return (r + l) * n / 2;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n];
    LL sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int last = 1;
    for(int i = 0; i < n; i++){
        int x = a[i] - last ;
        if(m >= x){
            x = min(m,x);
            m-= x;
            sum += get(last,last + x - 1);
            last = a[i] + 1;
        }
    }
    if (m){
        sum += get(last,last + m - 1);
    }
    cout << sum;
}