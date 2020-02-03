#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
bool cond (int x){
    while (x > 0){
        int d = x %10;
        if (mp[d]) return true;
        x/=10;
    }
    return false;

}
int main (){
    int n;
    cin >> n;
    int y = n;
    while (y > 0){
        int x = y % 10;
        mp[x]++;
        y/=10;
    }
    int ans  = 0;
    for (long long int i = 1; i*i <= n;i++){
        if ( n % i  == 0){
            ans += cond (i);
            if (n/i != i) ans += cond(n/i);
        }
    }
    cout << ans ;
}
