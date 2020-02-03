#include <bits/stdc++.h>
using namespace std;
int a , b, i ;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n ;
    while (n--){
        cin >> a >> b >> i;
        int x = a ^ b;
        if (i%3 == 0) cout << a ;
        if (i%3 == 1) cout << b ;
        if (i%3 == 2) cout << x ;
        cout << "\n";
    }
}
