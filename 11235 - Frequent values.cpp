#include <bits/stdc++.h>
using namespace std;
int const MAXN = 100005;
int a [MAXN];
struct nd {
    int a,occa;
    int b,occb;
    int mx;
};
nd tree [4*MAXN];
nd get (nd l, nd r){
    nd ret;
    ret.a = l.a;
    ret.b = r.b;
    ret.mx = 0;
    if (l.b == r.a)
    ret.mx = l.occb + r.occa;
    if (l.a == r.a){
        ret.occa = l.occa + r.occa;
    }else ret.occa = l.occa;
    if (r.b == l.b){
        ret.occb = r.occb+l.occb;
    }else ret.occb = r.occb;
    ret.mx = max(r.mx,ret.mx);
    ret.mx = max(l.mx,ret.mx);
    return ret;
}
nd init (int x){
    nd ret;
    ret.a = x;
    ret.b = x;
    ret.occa = ret.occb = ret.mx = 1;
    return ret;
}
void build (int node, int start, int end){
    if (start == end){
        tree[node] = init(a[start]);
         return;
    }
    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid + 1, end);
    tree[node] = get(tree[2*node],tree[2*node + 1]);
}
nd query (int node, int start, int end, int l, int r){
    nd ret;
    ret.occa = ret.occb = ret.mx = 0;
    if (r < start or end < l) return ret;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end)/2;
    nd q1 = query (2*node, start, mid, l, r);
    nd q2 = query (2*node+1, mid + 1, end, l, r);
    return get(q1,q2);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    while(cin >> n && n){
        cin >> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        build(1,0, n - 1);
        while (q--){
            int l,r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r).mx << "\n";
        }
    }

}
