#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
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
    int n;
    cin >> n;
    cin >> s;
    int sum = 0;
    for (auto c : s){
        if (c == ')') sum--;
        else sum++;
    }
    if (sum != 0){
        cout << -1 << endl;
        return 0;
    }
    sum = 0;
    int ans = 0;
    bool cond = true;
    int start  = 0;
    for (int i = 0; i < n; i++){
        char c = s[i];
        if (c == ')') sum--;
        else {
            sum++;
        }
        if (sum < 0 && cond) cond = false,start = i;
        if (sum == 0){
            if (!cond){
                ans += (i - start + 1);
            }
            cond = true;
        }
    }
    cout <<  ans << endl;
}