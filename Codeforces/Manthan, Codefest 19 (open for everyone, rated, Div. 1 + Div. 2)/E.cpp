#include <bits/stdc++.h>
using namespace std;
int d[100];
int a[5000][5000];
int main (){
    //ios_base::sync_with_stdio(0);
   //cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    for (int i =0; i <n;i++){
        for (int j =0; j <n;j++){
            cin>>a[i][j];
            for (int k = 0; k<6 ; k++){
                int x = (a[i][j] & (1<<k))>>k;
                cout << x;
            }
            cout << "  ";
        }
        cout << endl;
    }

}
