#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    LL n;
    LL x,y;
    cin >> n >> x >> y;
    LL big = (y-n+1);
    if (y < n or big*big+ n-1 < x){
        cout << -1;
    }else{
        for (int i = 1; i < n;i++)
            cout << 1 << "\n";
        cout << big;
    }


}
