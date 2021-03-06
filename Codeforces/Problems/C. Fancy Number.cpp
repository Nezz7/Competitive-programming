#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
bool cmp (pair<pair<int,int>,pair<char,char>> a , pair<pair<int,int>,pair<char,char>> b){
    int nbrA = a . first . first;
    int nbrB = b . first . first;
    int iA = a . first . second;
    int iB = b . first . second;
    char siA  = a . second .first;
    char siB  = b . second .first;
    char cA = a . second . second;
    char cB = b . second . second;
    if (nbrA == nbrB){
        if (iA < iB  ) return cA < siA;
        if (iB < iA  ) return cB > siB;
    }
    return nbrA < nbrB;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin .tie(0),cout. tie(0);
    cin >> n >> k;
    cin >> s;
   vector <pair<int,string>> ans;
    for (char c = '0' ; c <= '9' ; c++){
        int cur = 0;
        vector <pair<pair<int,int>,pair<char,char>>> v;
        for (int i = 0 ; i < n ; i++){
            v.push_back({{abs(s[i]-c),i},{s[i],c}});
        }
        sort(v.begin(),v.end(),cmp);
        string str = s;
        for (int i = 0 ; i < k ;i++){
             int idx = v[i].first.second;
             cur += v[i].first.first;
             str [idx] = c ;
        }
        ans.emplace_back(cur,str);
    }
    sort(ans.begin(),ans.end());
    cout << ans[0].first << "\n" << ans[0].second << "\n";

}
