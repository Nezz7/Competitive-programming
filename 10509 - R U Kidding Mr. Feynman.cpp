 #include <bits/stdc++.h>
 using namespace std;
 int main (){
    double x;
    while (cin >> x && x){
        int  a = x;
        int q = sqrt(a);
        double ans = q + (1/(2.0)*q);
        cout << ans <<"\n";
    }

 }
