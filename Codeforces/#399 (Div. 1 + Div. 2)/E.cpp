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
string first = "NO";
string second = "YES";
int get(int x, LL msk){
    if(x == 0) return 0;
    set<int> st;
    for(int i = 1; i <= 60; i++){
        int bit = !!(msk & (1LL << i));
        if(i <= x && !bit) st.insert(get(x - i, msk | (1LL << i)));
    }
    int ret = 0;
    while(true){
        if(!st.count(ret)) return ret;
        ret++;
    }
}
int grundy(int x){
    int ret = 1;
    while(ret * (ret + 1) / 2 <= x) ret++;
    return ret - 1;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt  ^= grundy(x);
    } 
    if(cnt) cout << first << endl;
    else cout << second << endl;
}