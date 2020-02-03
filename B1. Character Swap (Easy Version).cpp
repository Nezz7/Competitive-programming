#include <bits/stdc++.h>
using namespace std;
int main (){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <char> v;
        vector <char> v2;
        for (int i = 0; i < n; i++){
             if (s[i]!=t[i]) v.push_back(s[i]),v2.push_back(t[i]);
        }
        if (v.size() == 0){
            cout << "Yes\n";
            continue;
        }
        if (v.size() == 2){
             if (v[0] == v[1] && v2[1] == v2[0]) cout << "Yes\n";
              else cout << "No\n";
              continue;
        }
        cout << "No \n";
    }
}
