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
LL n, L;
LL get_grundy(LL x){
    LL ret = 1;
    while(x % 2 == 0){
        x /= 2;
        ret *= 2;
    }
    return ret;
}
struct Trie{
    static const int K = 2;
    struct Vertex {
        int next[K];
        bool leaf = false;
        int lvl = 0;
        Vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add_string(string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - '0';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
                int idx = sz(trie) - 1;
                trie[idx].lvl = trie[v].lvl+ 1;
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
    }
    int change = 0;
    int notchange = 0;
    bool diff(int x, int y){
        if (x > y) swap(x,y);
        return (x == -1 && y!= -1);
    }
    vector<LL> numbers;
    void dfs(int node){
        if(node == -1) return;
        if(diff(trie[node].next[0],trie[node].next[1])){
            numbers.push_back(get_grundy(L- trie[node].lvl));
        }
        dfs(trie[node].next[0]);
        dfs(trie[node].next[1]);
    }
    void solve(){
        dfs(0);
        LL ans = 0;
        for(auto x : numbers) ans = x  ^ ans;
        if(ans)
        cout << "Alice";
        else  cout << "Bob";
    }
};


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> L;
    Trie trie;
    for(int i  = 0; i < n; i++){
        string s;
        cin >> s;
        trie.add_string(s);
    }
    trie.solve();
}