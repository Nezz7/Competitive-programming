#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        pair<LL,int> a[n];
        LL ans = 0;
        for (int i = 0; i <n;i++){
            LL x;
            cin >> x;
            a[i] = {x,i};
            ans+=x;
        }
        if (m < n or n == 2){
            cout << -1 <<"\n";
            continue;
        }
        sort(a,a+n);
        ans = 2LL * ans;
        vector<pair<int,int>> edges;
        for (int i = 0; i < n;i++){
            edges.emplace_back((i%n) + 1,(i+1) % n +1);
        }
        m-=n;
        for (int i = 0 ; i <m ;i++){
            ans+=a[0].first + a[1].first;
            edges.emplace_back(a[0].second+1 , a[1].second+1);
        }
        cout << ans << "\n";
        for (auto cur : edges){
            cout << cur.first << " " << cur.second << "\n";
        }
    }
}
