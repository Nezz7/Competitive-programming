#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6 + 5;
int f[500];
int x, cnt, cnt2, cnt3;

int main(){
    int n;
    cin >> n;
    f[0]  = 0;
    for (int i = 1; i <= n ;i++){
         f[i] = f[i-1] + i;
         cout << f[i] << endl;
    }

}
