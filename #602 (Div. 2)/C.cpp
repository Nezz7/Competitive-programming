#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e5+9;
string s;
int n,k;
int get_nxt(int i, char c){
    for (int j = i; j < n ;j++)
        if (s[j] == c) return j;
    return -1;
}
void go (int i , int x){
    string c = s.substr(i,x-i+1);
    reverse(c.begin(),c.end());
    for (int j = i ; j<=x;j++)
        s[j] = c[j-i];
}
int main (){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        k--;
        cin >> s;
        vector<pair<int,int>> ans;
        for (int i = 0; i <n ; i++){
            if (k == 0){
                if (s[i] == '(' ) continue;
                int x = get_nxt(i,'(');
                if (x != -1 && x!=i){
                            ans.emplace_back(i,x);
                            go(i,x);
                    }
            }else {
                if (i%2 == 0){
                    if (s[i] == '(' ) continue;
                    int x = get_nxt(i,'(');
                    if (x!=i && x!= -1){
                            ans.emplace_back(i,x);
                            go(i,x);
                    }
                }else {
                    k--;
                     if (s[i] == ')' ) continue;
                     int x = get_nxt(i,')');
                    if (x!=i && x!= -1){
                            ans.emplace_back(i,x);
                               go(i,x);

                    }
                }
            }
        }
        cout << ans.size()<<"\n";
        for (auto cur : ans){
            cout << cur.first + 1 << " " << cur.second + 1 << endl;
        }
    }
}
