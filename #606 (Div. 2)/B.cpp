#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int occ [MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        map<int,int> mp;
        for (int i = 0; i < n ; i++){
           int x;
           cin >> x;
            mp[-x]++;
        }
        LL ans = 0;
        for (auto cur : mp){
            if (cur.first%2 == 0){
                int x = cur.first/2;
                mp[x]++;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
