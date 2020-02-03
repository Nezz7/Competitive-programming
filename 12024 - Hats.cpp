#include <bits/stdc++.h>
using namespace std;
int ans[15] = {1 ,2 ,9 ,44 ,265 ,1854 ,14833 ,133496 ,1334961 ,14684570 ,176214841 };
int main (){

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        long long int p = 1;
        for (long long int i = 2; i <= n ;i++)
            p*=i;
        cout << ans[n-2] << "/" << p << "\n";
    }
}
