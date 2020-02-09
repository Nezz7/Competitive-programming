#include <bits/stdc++.h>
using namespace std;
int get_sum(int x){
    int ret = 0;
    while (x > 0){
        ret += x % 10;
        x/=10;
    }
    return ret&1;
}
int main (){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n ; i++){
        int x;
        cin >> x;
        ans+= get_sum(x);
    }
    cout << ans ;
}
