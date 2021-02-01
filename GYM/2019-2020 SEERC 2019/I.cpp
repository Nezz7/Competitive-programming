#include "bits/stdc++.h"
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define inside(x,a,b) ((a)<=(x)&&(x)<=(b))
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define LL long long
#define pii pair<int,int>
//#define int long long
const int INF = 1e9;
const int N = 1e3;
int n,a[N+2],b[N+2];

int main(){ FAST
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    int ans = 0;
    for(int i=1; i<=n; ++i){
        int tans = INF;
        for(int j=1; j<=n; ++j) tans = min(tans, abs(a[i]-b[j]));
        ans = max(ans, tans);
    }

    cout << ans << '\n';
}