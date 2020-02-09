#include <bits/stdc++.h>
using namespace std;
char m[1000][1000];
int  A[100];
int main (){
    int a, b, c, d, n;
    int s = 0;
    cin >> a >> b >> c >> d >> n;
    for (int i  = 0; i < n; i++)
        cin >> A[i], s += A[i];
    if ( a*b + c * d < s){
        cout << "No";
        return 0;
    }
    cout << "YES\n";
    int cur = 0;
    int id = 0;
    if (b > d){
        cur = d % 2;
    }else cur = (b + 1) % 2;
    for (int i = 0; i < min(d,b);i++){
        if (id == n) break;
        if (cur % 2 == 0){
             for (int j = 0; j < a + c; j++){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
            }
        }else {
            for (int j = a + c - 1; j >= 0; j--){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
            }
        }
        cur ++;
    }
    if (b > d){
        for (int i = d; i < b ;i++){
            if (id == n) break;
        if (cur % 2 == 0){
             for (int j = 0; j < a ; j++){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
            }
        }else {
            for (int j = a - 1; j >= 0; j--){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
            }
        }
                cur ++;
        }
    }else {
         for (int i = b; i < d ;i++){
            if (id == n) break;
            if (cur % 2 == 0){
             for (int j = a ; j < a + c; j++){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
                }
            }else {
            for (int j = a + c - 1 ; j >= a; j--){
                    m[i][j] = 'a' + id;
                    A[id] --;
                    if (A[id] == 0) id++;
                    if (id == n) break;
                }
            }
            cur ++;
            }
    }
    for (int i = 0; i < max(b,d); i++){
        for (int j = 0; j < a+c ;j++)
            if (m[i][j] != 0) cout << m[i][j];
            else cout << '.';
        if (i +1 != max(b,d))
        cout << endl;
    }
    return 0;
}
