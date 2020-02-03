#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 3000;
bool cond ;
LL tree[4*MAXN];
int a[MAXN];
LL gcd (LL a ,LL b){
    if (b == 0) return a;
    return gcd (b, a % b);
}
LL lcm (LL a, LL b){
    return a*b/gcd(a,b);
}
void build (int node, int start, int end){
    if (start == end){
         tree[node] = 1LL *a[start];
         return;
    }
    int mid = (start + end)/2;
    build (2*node, start, mid);
    build (2*node + 1, mid + 1, end);
    tree[node]= lcm(tree[2*node],tree[2*node + 1]);
}
LL query (int node, int start, int end, int l, int r){
    if (r < start or end < l) return 1;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end)/2;
    LL q1 = query(2*node, start, mid, l, r);
    LL q2 = query (2*node + 1, mid + 1, end, l, r);
    return lcm (q1,q2);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0); cout . tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        LL sum[n+5];
        sum[0] = 0;
        LL ans = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum[i + 1] = (LL)a[i] + sum[i];
        }
        build (1,0,n-1);
       for (int L = 0; L < n ;L++){
            for (int R = L; R < n ;R++){
                LL cur = sum[R+1] - sum[L];
                LL lm = query(1,0,n-1,L,R);
                if (lm <= 0) continue;
                if (cur % lm == 0) ans++;
            }
        }
        cout << ans <<"\n";
    }
}
