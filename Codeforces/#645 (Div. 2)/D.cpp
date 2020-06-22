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
LL a[MAXN],have[MAXN], add[MAXN];
LL get(LL x){
    return x * (x + 1) / 2;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, x;
    cin >> n >> x;
    LL sum = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    have [0] = 0;
    for(int i = 0; i < n; i++) have[i + 1] = have[i] + a[i];
    add[0] = 0;
    for(int i = 0; i < n; i++){
        add[i + 1] = add[i] + get(a[i]);
    }
    if (x == sum){
        LL ans = 0;
        for(int i = 0; i < n; i++) ans += get(a[i]);
        cout << ans << endl;
        return 0;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++){
        LL cur = 0;
        if(x >= a[i]) {
            LL xx = x - a[i];
            cur += get(a[i]);
            int l = 0;
            int r = i - 1;
            if(r < 0){
                l = i + 1;
                r = n - 1;
            }
            if(have[r + 1] - have[l] <= xx){
                cur += add[r + 1] - add[l];
                xx -= have[r + 1] - have[l];
                l = i + 1;
                r = n - 1;
            }
            int to = r;
            int low = l, hi = r;
            while(low <= hi){
                int mid = (low + hi + 1) / 2;
                if(have[r + 1] - have[mid] <= xx){
                    to = mid;
                    hi = mid - 1;
                }else low = mid + 1;
            }
            if(xx == 0){
                ans = max(cur,ans);
                continue;
            } 
            if(xx >= have[r + 1] - have[to]){    
                cur += add[r + 1] - add[to];
                xx -= have[r + 1] - have[to];
            }else to++;
            if(xx > 0){
                LL r = a[to - 1];
                LL l = a[to - 1] - xx + 1;
                cur += (r + l) * ( r - l + 1) / 2;  
            }
            ans = max(cur,ans); 
        }else {
            LL r = a[i];
            LL l = a[i] - x + 1;
            cur = (r + l) * ( r - l + 1) / 2;
        }
        ans = max(cur,ans);
    }
    cout << ans << endl;
}