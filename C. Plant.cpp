#include <bits/stdc++.h>
#define LL long long int
using namespace std;
typedef vector<vector<LL>> matrix;
int const oo = 1e9;
int const mod = 1e9+7;
matrix operator * (matrix &a, matrix &b){
    int n = (int) a.size();
    int m = (int) b.size();
    int p = (int) b[0].size();
    matrix c;
    c.resize(n);
    for (int i = 0; i < n; i++){
        c[i].assign(p,0);
        for (int j = 0; j < p; j++){
            for (int k = 0; k < m; k++){
                 c[i][j] += ((a[i][k] * b[k][j]) % mod);
                 c[i][j] %= mod;
            }
        }
    }
    return c;
}
matrix id (int n){
    matrix a;
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i].assign(n,1);
        a[i][i]  = 0;
    }
    return a;
}
matrix matrixExp(matrix a , LL n){
    if (n == 0) return id (a.size());
    matrix c = matrixExp(a,n/2);
    c =  c * c;
    if (n % 2) c = c * a;
    return c;
}
int main (){
    LL  n;
    cin >> n;
    matrix a = id (2);
    a[0][0]= 3;
    a[1][1]= 3;
    a[0][1]= 1;
    a[1][0]= 1;
    a = matrixExp(a,n);
    if (n == 0) a[0][0] = 1;
    cout << a[0][0] << endl;
}
