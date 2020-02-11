#include <bits/stdc++.h>
using namespace std;
int x[3],y[3];
int a,mx;
char g[150][150];
int ind;
void go (int ind, int x , int y, int xx , int yy){
    char c = ind + 'A';
    for (int i = x; i < x+xx; i++){
        for (int j= y; j < y+yy; j++)
            g[i][j] = c;
    }
}

int main (){
    for (int i = 0;i < 3; i++){
        cin >> x[i] >> y[i];
        a += x[i] * y[i];
        if (x[i] < y[i]) swap(x[i],y[i]);
        mx = max(x[i],mx);
        mx = max(y[i],mx);
        if (x[i] == mx)   ind = i;
    }
    int s = sqrt(a);
    if (s * s != a or mx != s){
        cout << -1;
        return 0;
    }
    cout << mx << endl;
    go (ind,0,0,y[ind],x[ind]);
    int l = ind;
    ind ++;
    ind %=3;
    if (mx - y[l] == y[ind] or x[ind] == mx)
    go (ind,y[l],0,y[ind],x[ind]);
    else  go (ind,y[l],0,x[ind],y[ind]);

    ind ++;
    ind %= 3;
    for (int i = 0; i <mx;i++){
        for (int j = 0; j < mx; j++){
            if(g[i][j] == 0) g[i][j] = ind + 'A';
            cout << g[i][j];
        }
        cout << "\n";
    }

}
