#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n , y, x;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int ans = 0;
    reverse(s.begin(),s.end());
    for (int i = 0; i < y ;i++)
        ans += (s[i] == '1');
    ans += (s[y] == '0');
    for (int i = y+1 ; i < x ;i++)
        ans += (s[i]=='1');
    cout << ans;
}
