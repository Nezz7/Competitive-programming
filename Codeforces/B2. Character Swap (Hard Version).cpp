#include <bits/stdc++.h>
using namespace std;
vector<set<int>> poS;
vector<set<int>> poT;
vector<pair<int,int>> ans;
string s,t;
void go (int id , int i){
    poT[t[i]-'a'].erase(i);
    poS[t[i]-'a'].insert(id);
    poS[s[id]-'a'].erase(id);
    poT[s[id]-'a'].insert(i);
    swap(t[i],s[id]);
    ans.emplace_back(id,i);
}

int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cin >> s >> t;
        poT.resize(26);
        poS.resize(26);
        for (int i = 0; i < n; i++){
            poS[s[i]-'a'].insert(i);
            poT[t[i]-'a'].insert(i);
        }
        bool cond = true;
        for (int i = 0; i < n; i++){
            if (s[i]!=t[i]){
                poS[s[i]-'a'].erase(i);
                if (poS[s[i]-'a'].size()){
                    int id = *(poS[s[i]-'a'].begin());
                    go(id,i);
                }else {
                    if (poT[s[i]-'a'].size()){
                        int id = *(poT[s[i]-'a'].begin());
                        go(id,id);
                        go(id,i);
                    }else cond = false;
                }
            }
            poS[s[i]-'a'].erase(i);
            poT[t[i]-'a'].erase(i);
        }
        if (cond ){
            cout << "Yes\n" << ans.size() <<"\n";
            for (auto cur : ans){
                cout << cur.first + 1 << " " << cur.second + 1 << "\n";
            }
        }else cout << "No\n";
        poT.clear();
        poS.clear();
        ans.clear();
    }
}
