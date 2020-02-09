#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
int pr[MAXN], a[MAXN];
map< vector < pair <int, int> >, int > cnt;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a [ i ];
    pr[1] = 1;
    for (int i = 2; i < MAXN; i++){
        if( !pr[i] ){
            for (int j = i; j < MAXN; j+=i)
                pr[j] = i;
        }
    }
    long long int  ans = 0;
    for (int i = 0; i < n; i++){
        vector< pair <int,int> > prf;
        int x = a[i];
        while (a[i] > 1){
            int d = pr[a[i]];
            int cur = 0;
            while (a[i] % d ==0){
                cur++;
                a[i]/= d;
            }
            if (cur % k )
                prf.emplace_back(d,cur%k);
        }
        sort(prf.begin(),prf.end());
        vector< pair<int,int> > need;
        for (auto cur : prf){
            need.emplace_back(cur.first,k-cur.second);
        }
        ans += cnt [need];
        cnt[prf]++;
    }
    cout << ans << "\n";
}
