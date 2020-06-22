#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1600;
int ans [MAXN][26];
int n, m, q;
char c;
string s;
int get (int m, char c){
    int id = c - 'a';
    if (ans[m][id] != -1) return ans[m][id];
    int start = 0;
    int cur = 0,i = 0;
    int ret = m;
    for (int i = 0 ; i < n ; i++ ){
         cur += (s[i] != c);
         while (cur > m){
            cur -= (s[start] != c);
            start ++ ;
         }
        ret = max(i - start + 1,ret);
    }
    return ans[m][id] = ret;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(ans, -1, sizeof ans);
    cin >> n ;
    cin >> s ;
    cin >> q ;
    while( q -- ){
        cin >> m >> c;
        cout << get(m, c) << "\n";
    }
}
