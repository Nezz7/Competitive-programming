#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int i = 1;
        set<int> ans;
        while (i*i <= n){
            ans.insert(i);
            ans.insert(n/i);
            i++;
        }
        cout << ans.size() << endl;
        for (auto cur : ans){
            cout << cur << " ";
        }
        cout << endl;
    }
}
