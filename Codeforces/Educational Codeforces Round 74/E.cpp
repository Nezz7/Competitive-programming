// to upsolve
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
map<pair<char,char>,int> mp;
map<char,int> id;
vector<deque<char>> key;
int get_id(char c){
    if(id.count(c)) return id[c];
    return -1;
}
int get_l(char c){
    int idx = get_id(c);
    if(idx == -1) return 0;
    int ret = 0;
    for(auto cur : key[idx]){
        if(cur == c)  break;
        ret++;
    }
    return ret;
}
int get_r(char c){
    int idx = get_id(c);
    if(idx == -1) return 0;
    int ret = 0;
    for(auto cur : key[idx]){
        if(cur == c)  break;
        ret++;
    }
    return sz(key[idx]) - ret - 1;
}
LL merge(char u, char v){
    int ru = get_r(u);
    int lu = get_l(u);
    int rv = get_r(v);
    int lv = get_l(v);
    cout << ru << " " << lu << endl;
    cout << rv << " " << lv << endl;
    if(ru + lv < rv + lu){
        swap(u,v);
    }
    int idu = get_id(u);
    int idv = get_id(v);
    if(idv == -1 && idu == -1){
        id[u] = sz(key);
        id[v] = sz(key);
        key.emplace_back();
        key[id[u]].push_front(u);
        key[id[u]].push_front(v);
    }
    if(idv != -1){
        if(idu == -1)
        key[id[v]].push_front(u);
        else {
            vector<char> cur;
            for(auto x : key[id[u]]){
                cur.pb(x);
            }
            reverse(all(cur));
            for(auto x : cur){
                id[x] = id[v];
                key[id[v]].push_front(x);
            }
        }
        id[u] = id[v];
    }
    return min(ru + lv , rv + lu);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] != s[i + 1]){
            mp[minmax(s[i],s[i+1])]++;
        }
    }
    priority_queue <pair<int,pair<char,char>>> pq;
    for(auto cur : mp){
        pq.push({cur.second,cur.first});
    }
    LL ans = 0;
    while(!pq.empty()){
        LL rep = pq.top().first;
        char u = pq.top().second.first;
        char v = pq.top().second.second;
        pq.pop();
        LL x = merge(u,v);
        cout << x << " " << u << " " << v << endl;
        ans += rep * x;
    }
    cout << ans << endl;

}