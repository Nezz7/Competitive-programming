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
string s[MAXN];
int nbr[MAXN];
char last[MAXN];
char v [] = {'a', 'e', 'o', 'i', 'u'};
int vis[MAXN];
map<pair<int,char>,vector<int>> mp;
void gen (int i){
    string cur = s[i];
    int n = sz(cur);
    for (int j = 0; j < n; j++){
        for (int k = 0; k < 5; k++){
            if (cur[j] == v[k]){
                nbr[i]++;
                last[i] = v[k];
            }
        }
    }
}
vector<pair<int,int>> p2,p1;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        gen(i);
        mp[{nbr[i],last[i]}].pb(i);
    }
    for(auto cur : mp){
        for(int i = 0; i < sz(cur.second) - 1; i+=2){
            vis[cur.second[i]] = 1;
            vis[cur.second[i + 1]] = 1;
            p2.emplace_back(cur.second[i],cur.second[i + 1]);
        }
    }
    mp.clear();
    for(int i = 0; i < n; i++){
        if(vis[i] == 0)
        mp[{nbr[i],'a'}].pb(i);
    }
    for(auto cur : mp){
        for(int i = 0; i < sz(cur.second) - 1; i+=2){
            vis[cur.second[i]] = 1;
            vis[cur.second[i + 1]] = 1;
            p1.emplace_back(cur.second[i],cur.second[i + 1]);
        }
    }
    int ans = min(sz(p1),sz(p2));
    if(sz(p2) > sz(p1)){
        ans += abs (sz(p1) - sz(p2)) / 2;
    }
    cout << ans << endl;
    int i = 0;
    int j = 0;
    while ( i < sz(p1) && j < sz(p2)){
        cout << s[p1[i].first] << ' ' << s[p2[j].first] << endl;
        cout << s[p1[i].second] << ' ' << s[p2[j].second] << endl;
        i++,j++;
    }
    while (j < sz(p2) - 1){
        cout << s[p2[j].first] << ' ' << s[p2[j + 1].first] << endl;
        cout << s[p2[j].second] << ' ' << s[p2[j + 1].second] << endl;
        j+= 2;
    }
}