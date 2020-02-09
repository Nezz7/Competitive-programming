#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int dp[MAXN][3];
int a[MAXN][3];
int rev[MAXN];
int should[MAXN];
int n;
map<string,int>mp;
LL ans ;
bool valid (int i,int x, int s){
    if (should[i] == should[x] && should[i] == -1) return true;
    if (should[i] == should[x] && s ==0) return true;
    if (should[i] != should[x] && s == 1) return true;
    return false;
}
int solve (int i, int last){
    if (i == n) return 0;
    int & ret = dp[i][last];
    if (ret != -1) return ret;
    ret = 1e9;
    int x = rev[i];
    if (x == -1) x = n;
    int l = should[x];
    int me = should[i];
    if (a[i][0] == last && valid(i,x,0)){
            should[x] = 0;
            should[i] = 0;
            ret = min(ret,solve(i+1,a[i][1]));
            should[x] = l;
            should[i] = me;
    }
    if (last == a[i][1] && valid (i,x,1)){
            should[x] = 1;
            should[i] = 1;
            ret = min(ret,1+solve(i+1,a[i][0]));
            should[x] = l;
            should[i] = me;
    }
    return ret;
}
void print (int i , int last){
    if (i == n) return ;
    if (a[i][0] == last && ans ==solve(i+1,a[i][1])) print(i+1,a[i][1]);
    else if (last == a[i][1] && ans == 1 + solve(i+1,a[i][0])){
             ans --;
             cout << i + 1 << " ";
             print(i+1,a[i][0]);
             }

}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);*/
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        ans = 0;
        mp.clear();
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <3; j++)
                dp[i][j] = -1;
            rev[i] = -1;
            should [i]= -1;
        }
        for (int i = 0; i < n;i++){
            string s;
            cin >> s;
            int sz = s.size();
            mp[s] = i + 1;
            a[i][0] = s[0] - '0';
            a[i][1] = s[sz - 1] - '0';
            reverse(s.begin(),s.end());
            int x = mp[s];
            if (x){
                rev[i] = x-1;
                rev[x-1] = i;
            }
        }
        for (int i = 0; i < n;i++) cout << i << " " << rev[i] << "\n";
        cout << endl;
            ans = min(solve(0,0),solve(0,1));
        if (ans == 1e9) cout << "-1\n";
        else{ cout << ans << "\n";
            if (ans == solve(0,0)) print(0,0);
            else if (ans == solve(0,1))print(0,1);
            cout << "\n";
        }
    }

}
