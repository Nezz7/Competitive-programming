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
int n, k;
string s;
int get(char c){
    int cnt = 0;
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == c){
            cnt++;
        }else {
            cnt = 0;
            ret = max(cnt, ret);
        }
    }
    return ret = max(cnt, ret);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;       
        bool cond = true;
        for(int i = n - 1; i >= k; i--){
            if(s[i] != '?' && s[i - k] != s[i]){
                if(s[i - k] == '?') s[i - k] = s[i];
                else cond = false; 
            }
        }
        for(int i = 0; i + k < n; i++){
            if(s[i] != '?' && s[i + k] != s[i]){
                if(s[i + k] == '?') s[i + k] = s[i];
                else cond = false; 
            }
        }
        int one = 0, zero = 0, mark = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == '1') one ++;
            else if(s[i] == '0') zero++;
            else mark ++;
        }
        bool f = false;
        for(int i = 0; i <= mark; i++){
            if((one + i) == (zero + mark - i)) f= true;
            swap(one,zero);
            if((one + i) == (zero + mark - i)) f= true;

        }
        if(f == false) cond = false;
        cout << (cond ? "YES" : "NO")  << endl;
    }
}