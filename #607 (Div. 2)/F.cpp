#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        set<int>adj[26];
        int i = 0;
        bool cond = false;
        for (auto c : s) adj[c-'A'].insert(i++);
        for (int i = 0; i <min(n,m); i++){
            adj[s[i] - 'A'].erase(i);
            if (s[i] < t[i]){
                 cond = true;
                 break;
            }
            if (s[i] > t[i]){
                for (int j = 0; j <= t[i]-'A'; j++){
                    if (adj[j].size()){
                        auto it = adj[j].end();
                        it--;
                        swap(s[i],s[*it]);
                        cond = true;
                        break;
                    }
                }
            }
            if (cond) break;
        }
        if (s < t){
            cout << s << "\n";
        }else cout << "---\n";
    }

}
