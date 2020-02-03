#include <bits/stdc++.h>
#define LL long long int
using namespace std;
const int MAXN = 2e5+9;
int go (LL a, LL b, LL c, LL d){
    LL x = a*d;
    LL y = b*c;
    if (x == y) return 0;
    if (x < y) return 1;
    return 2;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0); cout . tie(0);
   LL n, x, y;
   cin >> n >> x >> y;
   LL a = 1;
   LL b = 1;
   vector<int> ans;
   int last;
   do{
        last = go(a,x,b,y);
        ans.push_back(last);
        if (last == 1){
            a++;
        }else b++;
   }while (last!=0);
   ans.push_back(0);
  int p = ans.size();
   while (n--){
        int a;
        cin >> a;
        a--;
        if (ans[a%p] == 1){
            cout << "Vanya\n";
        }else if (ans[a%p] == 2){
            cout << "Vova\n";
        }else cout << "Both\n";
   }
}
