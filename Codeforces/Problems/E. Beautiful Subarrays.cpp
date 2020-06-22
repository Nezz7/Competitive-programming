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
const int K = 2;
struct Vertex {
    int next[K];
    int sz;
    bool leaf;
    Vertex() {
        fill(begin(next), end(next), -1);
        sz = 0;
        leaf = false;
        }
};
vector<Vertex> trie(1);
void add(int x) {
    int v = 0;
    for(int i = 31; i >= 0; i--) {
        int c = ((x &(1 << i))>> i);
        trie[v].sz++;
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
    trie[v].sz++;
}
LL solve(int cur,int k){
    int v = 0;
    LL ret = 0;
    for(int i = 31; i >= 0; i--) {
        int c = ((k &(1 << i)) >> i);
        int x = ((cur & (1 << i)) >> i);
        int p = -1;
        for(int y = 0; y < 2 ; y++){
        if(trie[v].leaf) {ret += trie[v].sz;}
            if ((y ^ x)> c && trie[v].next[y] != -1)
                ret += trie[trie[v].next[y]].sz;
            if((y ^ x) == c ) p = y;
        }
        if(p == -1) {break;}
        v = trie[v].next[p];
        if(v == -1) break;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cur = 0;
    add(0);
    LL ans = 0;
    for(int i = 0; i < n; i++){
        cur = cur ^ a[i];
        ans += solve(cur,k);
        add(cur);
    }
    cout << ans << endl;
}
