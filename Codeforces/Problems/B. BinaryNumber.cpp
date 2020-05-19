#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    while (n > 1 && s[n - 1] == '0') ans++,n--;
    int cnt = 0;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(cnt){
                ans += (i - last - 1)* 2;
            }
            last = i;
        }
        cnt += (s[i] == '1');

    }
    if(cnt > 1)  cnt++;
    else cnt --;
    ans += cnt;
    cout << ans;
}