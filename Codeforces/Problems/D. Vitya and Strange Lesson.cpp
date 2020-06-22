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
struct Trie{
    static const int K = 26;
    struct Vertex {
        int next[K];
        bool leaf = false;
        Vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add(int x) {
        int v = 0;
        for (int i = 30; i >= 0; i--) {
            int c = ((x >> i) & 1);
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
    }
    int solve (int x){
        int ret = 0;
        int v = 0;
        for (int i = 30; i >= 0; i--) {
            int c = ((x >> i) & 1);
            if(trie[v].next[c] == -1) return ret;
            ret |= (c << i);
            v = trie[v].next[c];
            if(v == -1) break;
        }
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    Trie trie;
    set<int> st;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
            trie.add(x);
    }
    int cur = 0;
    while(q--){
        int x;
        cin >> x;
        cur ^= x;
        cout << (trie.solve(cur) ^ cur)<< endl;
    }

}