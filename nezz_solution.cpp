#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6+9;
struct nd {
    int mx;
    int pref,suf;
    int p,s,c;
};
nd tree[2][4*MAXN];
int a[MAXN],lazy[4*MAXN];
void propagate (int node,int start, int end){
    if (lazy[node]){
        swap(tree[0][node],tree[1][node]);
        if (start != end){
            lazy[2*node] ^=1;
            lazy[2*node + 1] ^=1;
        }
        lazy[node] = 0;
    }
}
nd init (int x, int p = 1){
    nd ret;
    ret.mx = ret.pref = ret.suf = ret.c = p;
    ret.p = ret.s = x;
    return ret;
}
nd merge (nd l, nd r){
    nd ret;
    ret.mx = max(l.mx,r.mx);
    ret.s = r.s;
    ret.p = l.p;
    if (r.c && l.c && r.p == l.s)
        ret.c  = 1;
    else ret.c = 0;
    if (r.c && (r.s >= l.s))
    ret.suf = r.suf + l.pref;
    else ret.suf = r.suf;
    if (l.c && l.p <= r.p)
    ret.pref = l.pref + r.suf;
    else ret.pref = l.pref;
    if (l.s <= r.p)
    ret.mx = max(ret.mx,l.suf + r.pref);
    return ret;
}
void build (int node, int start, int end){
    lazy[node] = 0;
    if (start == end){
        tree[0][node] = init(a[start]);
        tree[1][node] = init(a[start]^1);
        return;
    }
    int mid = (start + end)/2;
    build(2*node, start, mid);
    build (2*node + 1, mid + 1, end);
    tree[0][node] = merge(tree[0][2*node],tree[0][2*node+1]);
    tree[1][node] = merge(tree[1][2*node],tree[1][2*node+1]);
}
void update (int node,int start,int end, int l,int r){
    propagate(node,start,end);
    if (r < start or end < l) return;
    if (l <= start && end <= r){
        lazy[node] = 1;
        propagate(node,start,end);
        return ;
    }
    int mid = (start + end)/2;
    update(2*node, start,mid,l,r);
    update(2*node+1, mid+1,end,l,r);
    tree[0][node] = merge(tree[0][2*node],tree[0][2*node+1]);
    tree[1][node] = merge(tree[1][2*node],tree[1][2*node+1]);
}
nd query (int node, int start, int end, int l, int r ){
    propagate(node,start,end);
    if (r < start or end < l) return init(0,0);
    if (l <= start && end <= r) return tree[0][node];
    int mid = (start + end)/2;
    nd q1 = query(2*node, start,mid,l,r);
    nd q2 = query(2*node+1, mid+1,end,l,r);
    return merge(q1,q2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            a[i] = (s[i] == '1');
        }
        build(1,0,n-1);
        while (q--){
            int  p,l,r;
            cin >> p >> l >> r;
            l--,r--;
            if (p == 2){
                cout << query(1,0,n-1,l,r).mx << "\n";
            }else {
                update(1,0,n-1,l,r);
            }
        }
 
    }
}