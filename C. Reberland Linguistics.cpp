#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e4+9;
int vis[MAXN][3][3];
string s;
set<string> st;
void solve (int n, bool a, bool b){
    if (vis[n][a][b]) return ;
    vis [n][a][b]= true;
    if (n - 2 >= 4 && a){
        int nxt = n-2;
        string str = s.substr(nxt-2+1,2);
        string cur = s.substr(n-2+1,2);
        st.insert(cur);
        if (str == cur ) a = false;
        solve (n-2,a,true);
    }
    if (n - 3 >= 4 && b){
        int nxt = n-3;
        string str = s.substr(nxt-3+1,3);
        string cur = s.substr(n-3+1,3);
        st.insert(cur);
        if (str == cur) b = false;
        solve (n-3,true,b);
    }
}
int main (){
    int n;
    cin >> s;
    n = s.size();
    solve (n-1, true, true);
    cout << st.size() << "\n";
    for (auto cur : st)
        cout << cur << "\n";

}
