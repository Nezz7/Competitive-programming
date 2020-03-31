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
int const MAXN = 1e5 + 9;
struct Trie{
    static const int K = 2;
    struct Vertex {
        int next[K];
        bool leaf = false;
        int mn;
        Vertex() {
            fill(begin(next), end(next), -1);
            mn = 1e9;
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add(int x) {
        int v = 0;
        for(int i = 31; i >= 0; i--) {
            int c = ((x & (1 << i)) >> i) ;
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            trie[v].mn = min(trie[v].mn,x);
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
        trie[v].mn = x;
    }
    int solve (int x,int s){
        int v = 0;
        int ret = 0;
        for(int i = 31; i >= 0; i--){
            bool cond = true;
            int c = ((x & (1 << i)) >> i) ;
            int nc = c ^ 1;
            if (trie[v].next[nc] != -1 && trie[trie[v].next[nc]].mn <= s ){
                cond = false;
                c = nc;
            }
            if (cond && trie[v].next[c] != -1 && trie[trie[v].next[c]].mn <= s ){
                cond = false;
            }
            if (cond) return -1;
            ret |= (c << i);
            v = trie[v].next[c];
        }
        return ret;
    }
};

Trie trie[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int x;
            cin >> x;
            for(LL i = 1; i*i <= x; i++){
                if(x % i == 0){
                    trie[i].add(x);
                    int j = x / i;
                    if(j != i) trie[j].add(x);
                }
            }
        }else {
            int x,k,s;
            cin >> x >> k >> s;
            if (x % k or s - x <= 0){
                cout << -1 << endl;
            }else {
                cout << trie[k].solve(x,s - x) << endl;
            }
        }
    }
}