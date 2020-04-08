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
#define int long long
using namespace std;
int const MAXN = 2e6 + 9;
int n;
LL m;
LL p[MAXN],c[MAXN];
bool check(LL x){
    LL ret = -m;
    for(int i = 0; i < n; i++){
        if (x * p[i] >= c[i]){
            ret -= c[i];
            ret += x * p[i];
        }
		if(ret >= 0) return true;
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> p[i] >> c[i];
    }
    LL l = 1, r = 4e9L;
    LL ans = -1;
    while(l <= r){
        LL mid = (l + r + 1) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid +1;
    }
	assert(ans != -1);
    cout << ans << "\n";
}