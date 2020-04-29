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
struct Trie{
    static const int K = 26;
    struct Vertex {
        int next[K];
        bool leaf = false;
        int mn = 0;
        Vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add_string(string const& s) {
        int fullcost = 1e9;
        int n = s.size();
        int last = 0;
        int v = 0;
        int i = 0;
        for (char ch : s) {
            int c = ch - 'a';
            last = trie[v].mn;
            if (trie[v].next[c] == -1) {
                fullcost = min(fullcost,last + 2);
                trie[v].next[c] = trie.size();
                trie.emplace_back();
                trie[sz(trie) - 1].mn = min(last + 1,fullcost + n - 1 - i);
            }
            v = trie[v].next[c];
            i++;
        }
        trie[v].leaf = true;
    }
    int solve(string const& s) {
        int ret = 0;
        int n = s.size();
        int v = 0;
        int i = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                return trie[v].mn + n - i;
            }
            v = trie[v].next[c];
            ret = trie[v].mn;
            i++;
        }
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,q;
    cin >> n >> q;
    Trie trie;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        trie.add_string(s);
    }
    while(q--){
        string s;
        cin >> s;
        cout << trie.solve(s) << endl;
    }
}