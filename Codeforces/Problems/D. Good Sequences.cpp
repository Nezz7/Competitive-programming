#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
int p[MAXN];
int dp[MAXN];
int main (){
    int n;
    cin >> n;
    p[1] = 1;
    for (int i = 2; i < MAXN; i++){
       if (!p[i])
        for (int j = i; j < MAXN; j+=i)
            p[j] = i;
    }
    int ans = 1;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        vector<int> v;
        int curmx = 0;
        while (x > 1){
            int d = p[x];
            dp[d]++;
            curmx = max(curmx,dp[d]);
            v .push_back(d);
            while (x % d == 0)
                x /= d;
        }
        for (auto cur : v){
            dp[cur] = max(dp[cur],curmx);
            ans = max(dp[cur],ans);
        }
    }
    cout << ans;
}
