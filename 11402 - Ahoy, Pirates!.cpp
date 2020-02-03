#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e6;
int a[MAXN];
int tree[4*MAXN], lazy[4*MAXN];
int change (int x , int u){
    if ( u == 1) return 1;
    if ( u == 2) return 2;
    if ( x == 1) return 2;
    if ( x == 2) return 1;
    if ( x == 3) return 0;
    if ( x == 0) return u;
}
int get_type (char c){
    if (c == 'F') return 1;
    if (c == 'E') return 2;
    return 3;
}
void build (int node, int start, int end){
    lazy[node] = 0;
    if (start == end){
        tree[node] = a[start];
        return ;
    }
    int mid = (start + end)/2;
    build (2*node, start, mid);
    build (2*node + 1, mid + 1, end);
    tree[node] = tree[2*node] + tree[2*node + 1];
}
void update (int node, int start, int end, int l, int r, int type){
        if (lazy[node]){
            if ( lazy[node] == 1) tree[node] = end - start + 1;
            if ( lazy[node] == 2) tree[node] = 0;
            if ( lazy[node] == 3) tree[node] = end - start + 1 - tree[node];
            if (start != end){
                lazy [2*node] = change(lazy[2*node],lazy[node]);
                lazy [2*node + 1] = change(lazy[2*node + 1],lazy[node]);
            }
            lazy[node] = 0;
        }

    if (end < l or  r < start) return;
    if (l <= start and end <= r){
            if (type == 1) tree[node] = end - start + 1;
            if (type == 2) tree[node] = 0;
            if (type == 3) tree[node] = end - start + 1 - tree[node];
            if (start != end){
                lazy [2*node] = change(lazy[2*node],type);
                lazy [2*node + 1] = change(lazy[2*node + 1],type);
            }
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, type);
    update(2*node + 1, mid + 1, end, l, r, type);
    tree[node] = tree[2*node] + tree [2*node + 1];
}
int query (int node, int start, int end, int l, int r){
    if (end < l or  r < start) return 0;
    if (lazy[node]){
            if ( lazy[node] == 1 ) tree[node] = end - start + 1;
            if ( lazy[node] == 2 ) tree[node] = 0;
            if ( lazy[node] == 3 ) tree[node] = end - start + 1 - tree[node];
            if (start != end){
                lazy [2*node] = change(lazy[2*node],lazy[node]);
                lazy [2*node + 1] = change(lazy[2*node + 1],lazy[node]);
            }
            lazy[node] = 0;
    }
    if (l <= start and end <= r) return tree[node];
    int mid = (start + end)/ 2;
    int q1 = query (2*node, start, mid, l, r);
    int q2 = query (2*node + 1, mid + 1, end, l, r);
    return q1 + q2;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin .tie (0); cout. tie (0);
    int T;
    cin >> T;
    int c = 1;
    while (T--){
        cout << "Case " << c << ":\n";
        int m;
        cin >> m;
        int n = 0;
        for (int i = 0; i < m;i++){
            int x; string s;
            cin >> x >> s;
            for (int k = 0; k < x; k++){
                for (auto cur : s)
                    a[n] = cur - '0',n++;
            }
        }
        build (1, 0, n-1);
        int q;
        cin >> q;
        int p = 1;
        for (int i = 0; i < q; i++){
            char t;
            int l, r;
            cin >> t >> l >> r;
            if (t == 'S'){
                cout << "Q" << p << ": " << query (1, 0, n - 1, l, r) << "\n";
                p++;
            }else update (1, 0, n - 1, l, r, get_type(t));
        }

        c++;
    }
}
