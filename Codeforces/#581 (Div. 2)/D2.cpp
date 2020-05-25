#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6+9;
struct nd {
    int mx;
    int nbr7,nbr4;
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
    ret.mx = 1;
    if (p){
    ret.nbr4 = 1 - x;
    ret.nbr7 = 1 - ret.nbr4;
    }else {
        ret.mx = 0;
        ret.nbr4 = 0;
        ret.nbr7 = 0;
    }
    return ret;
}
nd merge (nd l, nd r){
    nd ret;
    ret.nbr7 = l.nbr7 + r.nbr7;
    ret.nbr4 = l.nbr4 + r.nbr4;
    ret.mx = max (l.mx + r.nbr7, l.nbr4 + r.mx);
    return ret;
}
void build (int node, int start, int end){
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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++){
        a[i] = (s[i] == '1');
    }
    build(1,0,n-1);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') continue;
        int last = query(1,0,n-1,0,n-1).mx;
        update(1,0,n-1,i,i);
        int cur = query(1,0,n-1,0,n-1).mx;
        if( cur == last){
            s[i] = '0';
            continue;
        }
        update(1,0,n-1,i,i);
    }
    cout << s << endl;
}