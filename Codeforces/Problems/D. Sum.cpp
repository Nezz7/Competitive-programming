#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cur = a[n-1];
    b[n-1] = 1;
    for (int i = n - 2; i >= 0; i --){
        if (cur >= 0){
            cur -= a[i];
            b[i] = 0;
        }else {
            cur += a[i];
            b[i] = 1;
        }
    }
    int x = 0;
    if (cur < 0){
        x = 1;
    }
    for (int i = 0; i < n; i++){
        b[i] ^=x;
        if (b[i]) cout << "+";
        else cout << "-";
    }
}
