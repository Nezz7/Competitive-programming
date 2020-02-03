#include <bits/stdc++.h>
using namespace std;
string add (string x ,string y){
    string res = "";
    int i = x.size();
    int j = y.size();
    i--,j--;
    int c= 0;
    while (i>=0  && j>=0){
        int a = x[i] - '0';
        int b = y[j] - '0';
        int r = (a + b + c) % 10;
            c = (a + b + c) / 10;
        char cc = '0'+r;
        res = cc + res;
        i--;
        j--;
    }
    while (i >= 0){
        int a = x[i] - '0';
        int b = 0;
        int r = (a + b + c) % 10;
            c = (a + b + c) / 10;
        char cc = '0'+r;
        res = cc + res;
        i--;
    }
    while (j >= 0){
        int a = 0;
        int b = y[j] - '0';
        int r = (a + b + c) % 10;
            c = (a + b + c) / 10;
        char cc = '0'+r;
        res = cc + res;
        j--;
    }
    if (c){
        char cc = '0'+ c;
        res = cc + res;
    }
    return res;
}
string mul (string x, string y){
    string res = "0";
    int n = (int) x.size() - 1;
    int m = (int) y.size() - 1;
        for (int j = m; j >= 0; j--){
            string cur = "";
            int a = y[j] - '0';
            int c = 0;
            for (int k = 0; k < m - j; k++)
                cur+="0";
            for (int i = n; i >= 0 ;i--){
                int b = x[i] - '0';
                int r = (a*b + c) % 10;
                    c = (a*b + c) / 10;
                char cc = '0'+ r;
                cur = cc + cur;

            }
        if (c){
                char cc = '0'+ c;
                cur = cc + cur;
        }

        res = add(res,cur);
    }
    return res;
}
int main (){
    string x,y;
    while(cin >> x >> y){
        if (y == "0" or x == "0") cout << "0\n";
        else cout << mul(x,y)<< "\n";
    }
}
