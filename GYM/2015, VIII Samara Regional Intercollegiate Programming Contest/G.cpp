#include <bits/stdc++.h>
#include <iostream>
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
    int n;
    cin >> n;
    vector<pair<int,int>> edges;
    stack<int> st;
    for(int i = 0; i < 2* n; i++){
        string s;
        int cur;
        cin >> s >> cur;
        if (s == "in"){
            if(st.empty()){
                st.push(cur);
            }else {
                edges.emplace_back(st.top(), cur);
                st.push(cur);
            }
        }else st.pop();
    
    }
    for(auto cur : edges){
        cout << cur.first << " " << cur.second << endl;
    }
}