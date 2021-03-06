#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5+9;
int last[MAXN],a[MAXN],d[MAXN];
int n,m;
bool check (int x){
    vector<pair<int,int>>v;
    memset(last,0,sizeof last);
    for (int i = 0; i < x; i ++)
         last[d[i]] = i;
   for (int i = 1; i <= m; i++){
      v.emplace_back(last[i],i);
   }
   sort(v.begin(),v.end());
   int  l = 0;
   int days = 0;
   for (auto cur : v){
        if (cur.first == 0) return false;
        days += (cur.first - l );
        if (days < a[cur.second]) return false;
        days -= a[cur.second];
        l = cur.first + 1;
   }
   return true;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 1; i <= m ;i++)
        cin >> a[i];
    int L = 1, R = n;
    int ans = -1;
    while (L <= R){
        int mid = (L + R)/2;
        if (check(mid)){
            ans = mid;
            R = mid - 1;
        }else  L= mid + 1;
    }
    cout << ans;
}
