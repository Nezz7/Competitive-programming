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
LL sumr[MAXN], suml[MAXN];
LL r[MAXN], l[MAXN];
bool ok (int x) {
    for (int i = 0; i <= x; i++){
        //cout << i << endl;
        //debug(suml[max(n-i,0)])
        //debug(sumr[max(n-(x-i),0)])
        if (suml[max(n-i,0)] + sumr[max(n-(x-i),0)] == 0) return true;
    }
    return false;
}
/*
1
4
1 2 2 2
1 2 2 1
*/
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
        map<LL,int> lr,ll;
        lr[0] = n;
        ll[0] = n;
        for (int i = 0; i < n; i++){
            sumr[i+1] = sumr[i] + r[i];
            suml[i+1] = suml[i] + l[i];
            lr[sumr[i+1]] = n - i - 1;
            ll[suml[i+1]] = n - i -1;
        }
        //for (auto cur : lr ) cout << cur.first <<  " " << cur.second << endl;
        int ans = 2*n;
        for (int i = 0; i <= n; i++){
            if (lr.count(-suml[i])) ans = min(ans,n-i +lr[-suml[i]]);
            if (ll.count(-sumr[i])) ans = min(ans,n-i +ll[-sumr[i]]);
        }
        cout << ans << endl;
    }
 }
