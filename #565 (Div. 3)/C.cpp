#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 5e5+9;
int b[] ={4,8,15,16,23,42};
int a[MAXN];
int n;
map<int,set<int>>mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0) ; cout . tie (0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >>a[i];
        mp[a[i]].insert(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < 6;j++){
            if (a[i] == b[j]){
                int p = *(mp[b[j-1]].begin());
                if (mp[b[j-1]].size() == 0){
                     ans++;
                    mp[b[j]].erase(i);
                    continue;
                }
                if (p < i){
                    mp[b[j-1]].erase(p);
                }else{
                    ans++;
                    mp[b[j]].erase(i);
                }
            }
        }
    }
    n -= ans;
    ans += n % 6;
    cout << ans << endl;

}
