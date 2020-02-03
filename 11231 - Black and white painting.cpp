#include <bits/stdc++.h>
using namespace std;
    int n, m , c ;
int main (){
    while(cin >> n >> m >> c && n){
        cout << ((n - 7) * (m - 7)  + c ) /2 << "\n";
    }
}
