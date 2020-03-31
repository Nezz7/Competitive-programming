#include <bits/stdc++.h>
#define f first
#define s second
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
struct Aho {
    static const int K = 26; //size of alphabet
    struct Vertex {
        int next[K];
        vector<int> matches;
        int p = -1;
        char pch;
        int link = -1;
        int exit_link = -1;
        int go[K];
        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };
    vector<Vertex> t;
    Aho (){
        t.emplace_back();
    }
    void add_string(string const& s,int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].matches.push_back(id);
    }
    void add_patterns(string pat[],int n){
        for(int i = 0; i < n; i++)
            add_string(pat[i],i);
    }
    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
    int get_exit_link(int v){
        if(t[v].exit_link == -1){
        if (v == 0 || t[v].p == 0)
                t[v].exit_link = 0;
            else {
                int link = get_link(v);
                if (link == 0 || sz(t[link].matches))
                    t[v].exit_link = link;
                else t[v].exit_link = get_exit_link(link);
            }
        }
        return t[v].exit_link;
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    } 
    vector<int> get_all_matches (int v){
        vector<int> ret;
        while(v){
            for(auto id : t[v].matches) ret.pb(id);
            v = get_exit_link(v);
        }
        return ret;
    }
    vector<vector<int>> get_all_occ(string t,int n){
        vector<vector<int>> occ(n);
        int cur = 0;
        int pos = 0;
        for(auto c : t){
            cur = go(cur,c);
            vector<int> ret = get_all_matches(cur);
            for(auto x : ret) occ[x].pb(pos);
            pos++;
        }
        return occ;
    }
};

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    string pat[q];
    int k[q];
    for(int i = 0; i < q; i++){
        cin >> k[i]>> pat[i];
    }
    Aho aho;
    aho.add_patterns(pat,q);
    vector<vector<int>> positions = aho.get_all_occ(s,q);
    for(int i = 0; i < q; i++){
        if(sz(positions[i]) < k[i]) cout << -1 << endl;
        else {
            int ans = 1e9;
            for(int j = 0; j + k[i] - 1 < sz(positions[i]); j++){
                ans = min(ans,positions[i][j + k[i] - 1] - positions[i][j] + sz(pat[i]));
            }
            cout << ans << endl;
        }
    }
}