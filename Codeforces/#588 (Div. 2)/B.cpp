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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n == 1 && k){
        cout << 0;
        return 0;
    }
    if(s[0] > '1' && k) s[0] = '1',k--;
    for(int i = 1; i < n; i++){
        if(s[i] != '0' && k){
            s[i] = '0';
            k--;
        }
    }
    cout << s;
}