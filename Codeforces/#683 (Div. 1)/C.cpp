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
int a[MAXN];
struct Trie{
    static const int K = 2;
    struct Vertex {
        int next[K];
        int leaf = 0;
        Vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add(int const& x) {
        int v = 0;
        for (int i = 30; i >= 0; i--) {
            int c = !!(x & (1LL<< i));
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
         trie[v].leaf = true;
    }

    int solve(int node){
        if(trie[node].leaf) {
            return 1;
        }
        int s0 = trie[node].next[0];
        int s1 = trie[node].next[1];
        if(s0 == -1){
            return solve(trie[node].next[1]);
        }
        if(s1 == -1){
            return solve(trie[node].next[0]);
        }
        return 1 + max(solve(trie[node].next[1]), solve(trie[node].next[0]));
    }
};

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    Trie trie;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        trie.add(a[i]);
    }
    cout << n - trie.solve(0) << endl;
}