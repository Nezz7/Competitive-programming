#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6+5;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n  = s.size();
    int ans = 0;
    for (int i = 0; i < n/2;i++){
        ans += (s[i]!=s[n-1-i]);
    }
    cout << ans ;
}
