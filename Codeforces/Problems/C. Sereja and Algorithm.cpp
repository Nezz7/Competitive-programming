#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5+9;
int sum[3][MAXN];
int main (){
    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++){
        sum[0][i+1] = sum[0][i];
        sum[1][i+1] = sum[1][i];
        sum[2][i+1] = sum[2][i];
        if(s[i] == 'x')
            sum[0][i+1]++;
        else if (s[i] == 'z')
            sum[1][i+1]++;
        else sum[2][i+1]++;
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        if (r - l +1 < 3){
            cout << "YES\n";
            continue;
        }
        l--;

        int x = sum[0][r]-sum[0][l];
        int z = sum[1][r]-sum[1][l];
        int y = sum[2][r]-sum[2][l];
        if (x && y && z){
            cout << "YES\n";
        }else cout << "NO\n";
    }

}
