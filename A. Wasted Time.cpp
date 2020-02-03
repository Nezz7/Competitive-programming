#include <bits/stdc++.h>
using namespace std;
double dist (int x, int y, int a, int b){
    int dx = x - a;
    int dy = y - b;
    return sqrt(dx*dx + dy*dy);
}
int main (){
    int n, k;
    cin >> n >> k;
    int x[n],y[n];
    for (int i = 0; i < n ;i++){
        cin >> x [i]  >> y [i];
    }
    double tot = 0;
    for (int i = 1; i < n ;i++){
        tot += dist(x[i],y[i],x[i-1],y[i-1]);
    }
     tot*=k;
    cout <<setprecision(20)<< tot/50.0;
}
