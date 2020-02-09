#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
char a[100][100];
bool can[0]
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        memset(can,false,sizeof can);
        for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            cin >>a[i][j];
            if (a[i][j] == 'A') cond = true;
            if (a[i][j] == 'P'){
                can[0] = false;
                v.push_back({i,j});
            }
        }
        if (!cond){
            cout << "MORTAL\n";
            continue;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){

            }
        }
    }
}
