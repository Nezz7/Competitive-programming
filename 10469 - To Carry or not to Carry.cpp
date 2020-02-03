#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    LL x,y;
    while (cin >> x >> y){
        LL ans = x ^ y;
        cout << ans << "\n";
    }
}
