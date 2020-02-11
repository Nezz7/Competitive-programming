#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
int n, m, k;
int tree[4*MAXN][6], a[MAXN][6];
vector <int> mrg (vector<int> l, vector<int> r){
        for (int i = 0; i < m; i++)
            l[i] = max(l[i],r[i]);
        return l;
}
vector <int> mrg (vector<int> l, int * r){
        for (int i = 0; i < m; i++)
            l[i] = max(l[i],r[i]);
        return l;
}
void build (int node, int start, int end){
    if (start == end){
        for (int i = 0; i < m; i++)
            tree[node][i] = a[start][i];
        return ;
    }
    int mid = (start + end)/2;
    build (2*node, start, mid);
    build (2*node + 1, mid + 1, end);
    for (int i = 0; i < m; i++)
        tree[node][i] = max (tree[2*node][i],tree[2*node + 1][i]);
}
vector<int> query (int node, int start, int end, int l, int r){
        vector<int> ret(5,0);
        if ( end < l or r < start ) return ret;
        if (l <= start and end <= r) return mrg (ret,tree[node]);
        int mid = (start + end) / 2;
        vector<int> L = query (2*node, start, mid, l, r);
        vector<int> R = query (2*node + 1, mid + 1, end, l, r);
        return mrg(L,R);
}
int get_sum (int L ,int R){
    vector<int> r = query(1, 0, n-1, L, R);
    int ret = 0;
    for (int i = 0; i < m; i++)
        ret+= r[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie(0), cout. tie (0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    build (1, 0, n-1);
    int ans = 0;
    int ansL = 0, ansR = 0;
    int L = 0, R = 0;
    int cur = get_sum(L,R);
 while (R < n && L <= R){
        while (cur <= k && R < n){
            if (R - L + 1 >= ans){
                ans = R - L + 1;
                ansL = L;
                ansR = R;
            }
            R++;
            cur = get_sum(L,R);
        }
        while(cur > k && L < R){
            L++;
            cur = get_sum(L,R);
        }
        if (L == R){
            R++;
            cur = get_sum(L,R);
        }
    }
    vector<int> ansV = query(1, 0, n-1, ansL, ansR);
    if (get_sum(ansL,ansR)> k){
        ansV = vector<int> (5,0);
    }
    for (int i = 0; i < m; i++)
        cout << ansV[i] << " ";
}
