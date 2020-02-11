#include <bits/stdc++.h>
using namespace std;
int const MAXN  = 30000 + 8;
string s;
struct nd {
   int sum;
   int minsum;
};
nd Tree[4 * MAXN];
void update (int node ,int start, int end , int id, char c){
    if (start == end){
         if (c == ')') Tree[node].sum = Tree[node].minsum = -1;
         else Tree[node].sum = Tree[node].minsum = 1;
        return;
    }
    int mid = (start + end)/2;
    if (start <= id && id <= mid)
        update (2*node, start, mid ,id,c);
    else update (2*node + 1, mid +1 , end , id,c);
    Tree[node].sum  = Tree[2*node].sum + Tree[2*node + 1].sum;
    Tree[node].minsum = min(Tree[2*node].minsum,Tree[2*node].sum + Tree[2*node+1].minsum);
}
char rev (char c){
    if (c == ')') return '(';
    return ')';
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0) , cout.tie(0);
    int n, test = 0;
    while (cin >> n ){
        if (n == 0) break;
        test ++;
        cout << "Test "<< test << ":\n";
        cin >> s;
        for (int i = 0; i < n;i++)
            update(1,0,n-1,i,s[i]);
        int q;
        cin >> q;

        while (q --){
            int x;
            cin >> x;
            x--;
            if (x == -1){
              if (!Tree[1].minsum && !Tree[1].sum) cout << "YES\n";
              else cout << "NO\n";
            }else {
                update (1,0,n-1,x,rev(s[x]));
                s[x] = rev(s[x]);
            }
        }
    }

}
