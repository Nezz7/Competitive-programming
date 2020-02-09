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
 int const MAXN = 2e5 + 9;
int n;
int sumr[MAXN], suml[MAXN];
int r[MAXN], l[MAXN];
bool ok (int x) {
    for (int i = 0; i <= x; i++){
        if (suml[n-i] + sumr[n-(x-i)] == 0) return true;
    }
    return false;
}
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> l[i];
            if (l[i] == 2) l[i] = -1;
        }
        for (int i = n-1; i >=0; i--){
            cin >> r[i];
            if (r[i] == 2) r[i] = -1;
        }
        sumr[0] = 0;
        suml[0] = 0;
        for (int i = 0; i < n; i++){
            sumr[i+1] = sumr[i] + r[i];
            suml[i+1] = suml[i] + l[i];
        }
        int L = 0, R = 2*n + 1;
        int ans = 0;
        while (L <= R){
            int mid = (L +R) / 2;
            if (ok(mid)){
                ans = mid;
                R = mid  - 1;
            }else L = mid + 1;
        }
        cout << ans << endl;
    }
 }
